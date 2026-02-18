import type { Difficulty, GameState, AIAction } from './types.js';
import { BallPredictor } from './ballPredictor.js';
import { KeyboardSimulator } from './KeyboardSimulator.js';
import { DIFFICULTY_SETTINGS } from './types.js';
import { ball, paddleright } from '../models/gamModels.js';


export class AIPlayer {
    private predictor: BallPredictor;
    private keyboardSim: KeyboardSimulator;
    private difficulty: Difficulty;
    
    private updateIntervalId: number | null = null;
    private movementIntervalId: number | null = null;
    private reactionTimeoutId: number | null = null;
    private isActive: boolean = false;
    private debugMode: boolean = false;

    private lastAction: AIAction = 'IDLE';
    private lastPrediction: any = null;
    private targetY: number | null = null; // Cible calculée toutes les 1 seconde
    private lastKnownPaddleHeight: number = 100;

    constructor(
        difficulty: Difficulty = 'medium',
        upKey: string = 'ArrowUp',
        downKey: string = 'ArrowDown'
    ) {
        this.difficulty = difficulty;
        this.predictor = new BallPredictor();
        this.keyboardSim = new KeyboardSimulator(upKey, downKey);
    }

    public start(): void {
        if (this.isActive) return;

        this.isActive = true;
        const updateFrequency = DIFFICULTY_SETTINGS[this.difficulty].updateFrequency;

        // every 1 second: observe + predict + calculate target
        this.updateIntervalId = window.setInterval(() => {
            this.update();
        }, updateFrequency);

        // while playing: continuous movement adjustment (60fps)
        this.movementIntervalId = window.setInterval(() => {
            this.continuousMovement();
        }, 16); // ~60fps

        if (this.debugMode) {
            console.log(`[AI] Started with difficulty: ${this.difficulty} (${updateFrequency}ms refresh)`);
        }
    }

    public stop(): void {
        if (!this.isActive) return;

        this.isActive = false;

        if (this.updateIntervalId !== null) {
            clearInterval(this.updateIntervalId);
            this.updateIntervalId = null;
        }

        if (this.movementIntervalId !== null) {
            clearInterval(this.movementIntervalId);
            this.movementIntervalId = null;
        }

        if (this.reactionTimeoutId !== null) {
            clearTimeout(this.reactionTimeoutId);
            this.reactionTimeoutId = null;
        }

        // Relâcher toutes les touches
        this.keyboardSim.releaseAll();

        if (this.debugMode) {
            console.log('[AI] Stopped');
        }
    }

    private update(): void {
        if (!this.isActive) return;

        const params = DIFFICULTY_SETTINGS[this.difficulty];
        const horizonMs = params.updateFrequency;

        const gameState = this.getGameState();
        if (!gameState) {
            if (this.debugMode) {
                console.warn('[AI] Cannot get game state');
            }
            return;
        }

        this.lastKnownPaddleHeight = gameState.aiPaddle.height || this.lastKnownPaddleHeight;

        const ballCenterYNow = gameState.ball.position.y + gameState.ball.radius;
        const coming = this.predictor.isBallComingTowardsAI(gameState);

        const impactPrediction = this.predictor.predictImpact(gameState);
        const posPrediction = this.predictor.predictPositionAt(gameState, horizonMs);
        this.lastPrediction = { impactPrediction, posPrediction };

        let baseCenterY = coming && impactPrediction.impactTime <= horizonMs
            ? impactPrediction.impactY
            : posPrediction.y;

        if (!coming) {
            baseCenterY = gameState.canvas.height / 2;
        }

        // Appliquer précision de prédiction (0..1) : moins précis => plus proche de la position actuelle
        const effectiveAccuracy = Math.max(0, Math.min(1, params.predictionAccuracy * impactPrediction.confidence));
        baseCenterY = (baseCenterY * effectiveAccuracy) + (ballCenterYNow * (1 - effectiveAccuracy));

        let targetCenterY = this.chooseStrategicTarget(gameState, baseCenterY);

        // Miss chance
        if (Math.random() < params.missChance) {
            targetCenterY = gameState.canvas.height / 2;
        }

        const humanError = (Math.random() - 0.5) * params.errorMargin * 2;
        targetCenterY += humanError;

        const halfPaddle = gameState.aiPaddle.height / 2;
        targetCenterY = Math.max(halfPaddle, Math.min(gameState.canvas.height - halfPaddle, targetCenterY));

        if (this.reactionTimeoutId !== null) {
            clearTimeout(this.reactionTimeoutId);
            this.reactionTimeoutId = null;
        }

        this.reactionTimeoutId = window.setTimeout(() => {
            if (!this.isActive) return;
            this.targetY = targetCenterY;

            if (this.debugMode) {
                console.log('[AI] Target updated:', {
                    coming,
                    horizonMs,
                    baseCenterY: baseCenterY.toFixed(1),
                    humanError: humanError.toFixed(1),
                    targetCenterY: targetCenterY.toFixed(1),
                    impactTime: impactPrediction.impactTime,
                    bounces: impactPrediction.bounces,
                    confidence: impactPrediction.confidence.toFixed(2),
                    effectiveAccuracy: effectiveAccuracy.toFixed(2)
                });
            }
        }, params.reactionTime);
    }

    private chooseStrategicTarget(gameState: GameState, predictedBallCenterY: number): number {
        const opponentCenterY = gameState.opponentPaddle.position.y + (gameState.opponentPaddle.height / 2);
        const maxOffset = gameState.aiPaddle.height * 0.25;
        const rawOffset = (predictedBallCenterY - opponentCenterY) * 0.3;
        const offset = Math.max(-maxOffset, Math.min(maxOffset, rawOffset));
        return predictedBallCenterY + offset;
    }

    private continuousMovement(): void {
        if (!this.isActive || this.targetY === null) return;

        const params = DIFFICULTY_SETTINGS[this.difficulty];
        const moveChance = Math.max(0, Math.min(1, params.speedMultiplier));

        const paddleY = paddleright.y;
        const paddleHeight = this.lastKnownPaddleHeight;
        const paddleCenter = paddleY + paddleHeight / 2;

        const deadZone = Math.max(8, Math.min(30, 8 + (1 - params.predictionAccuracy) * 20));

        if (moveChance < 1 && Math.random() > moveChance) {
            this.keyboardSim.pressContinuous('IDLE');
            return;
        }

        if (paddleCenter < this.targetY - deadZone) {
            this.keyboardSim.pressContinuous('DOWN');
        }
        else if (paddleCenter > this.targetY + deadZone) {
            this.keyboardSim.pressContinuous('UP');
        }
        else {
            this.keyboardSim.pressContinuous('IDLE');
        }
    }




    private getGameState(): GameState | null {
        const field = document.querySelector(".pong-field") as HTMLElement;
        const paddleLeftEl = document.querySelector(".paddle-left") as HTMLElement;
        const paddleRightEl = document.querySelector(".paddle-right") as HTMLElement;

        if (!field || !paddleLeftEl || !paddleRightEl) {
            return null;
        }

        return {
            ball: {
                position: { x: ball.x, y: ball.y },
                velocity: { x: ball.vx, y: ball.vy },
                radius: ball.size / 2
            },
            aiPaddle: {
                position: { x: paddleRightEl.offsetLeft, y: paddleright.y },
                width: paddleRightEl.clientWidth,
                height: paddleRightEl.clientHeight,
                side: 'right'
            },
            opponentPaddle: {
                position: { x: paddleLeftEl.offsetLeft, y: paddleLeftEl.offsetTop },
                width: paddleLeftEl.clientWidth,
                height: paddleLeftEl.clientHeight
            },
            canvas: {
                width: field.clientWidth,
                height: field.clientHeight
            }
        };
    }

    public setDifficulty(difficulty: Difficulty): void {
        const wasActive = this.isActive;
        
        if (wasActive) {
            this.stop();
        }

        this.difficulty = difficulty;

        if (wasActive) {
            this.start();
        }

        if (this.debugMode) {
            console.log(`[AI] Difficulty changed to: ${difficulty}`);
        }
    }

    public getStats() {
        return {
            difficulty: this.difficulty,
            isActive: this.isActive,
            lastAction: this.lastAction,
            lastPrediction: this.lastPrediction,
            params: DIFFICULTY_SETTINGS[this.difficulty]
        };
    }


    public setKeys(upKey: string, downKey: string): void {
        this.keyboardSim.setKeys(upKey, downKey);
    }

}