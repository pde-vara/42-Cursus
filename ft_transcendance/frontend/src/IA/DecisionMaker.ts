import type { AIAction, Difficulty, PredictionResult, DifficultyParams } from './types.js';
import { DIFFICULTY_SETTINGS } from './types.js';

export class DecisionMaker {
    private difficulty: Difficulty;
    private params: DifficultyParams;

    constructor(difficulty: Difficulty = 'medium') {
        this.difficulty = difficulty;
        this.params = DIFFICULTY_SETTINGS[difficulty];
    }


    public decide(
        prediction: PredictionResult,
        currentPaddleY: number,
        paddleHeight: number
    ): AIAction {
        if (this.shouldMiss()) {
            return this.getRandomAction();
        }

        const paddleCenter = currentPaddleY + (paddleHeight / 2);

        let diff = prediction.impactY - paddleCenter;

        const error = this.getRandomError();
        diff += error;

        diff *= prediction.confidence;

        const deadZone = this.getDeadZone();
        if (Math.abs(diff) < deadZone) {
            return 'IDLE';
        }

        return diff > 0 ? 'DOWN' : 'UP';
    }


    private shouldMiss(): boolean {
        return Math.random() < this.params.missChance;
    }


    private getRandomError(): number {
        const range = this.params.errorMargin;
        return (Math.random() - 0.5) * 2 * range;
    }


    private getDeadZone(): number {
        const baseDeadZone = 30;
        return Math.max(10, baseDeadZone * (1 - this.params.predictionAccuracy * 0.7));
    }

    private getRandomAction(): AIAction {
        const actions: AIAction[] = ['UP', 'DOWN', 'IDLE'];
        return actions[Math.floor(Math.random() * actions.length)] ?? 'IDLE';
    }

    public setDifficulty(difficulty: Difficulty): void {
        this.difficulty = difficulty;
        this.params = DIFFICULTY_SETTINGS[difficulty];
    }

    public getParams(): DifficultyParams {
        return { ...this.params };
    }

    public evaluatePosition(
        targetY: number,
        currentY: number,
        confidence: number
    ): number {
        const distance = Math.abs(targetY - currentY);
        const normalizedDistance = 1 - (distance / 500);
        
        return normalizedDistance * confidence;
    }
}