import { Match } from "../game/match.js";
import {} from "../models/pageType.js";
import { createPlayer } from "../models/player.js";
import { gameState } from "../router.js";
const MAX_BOUNCE_ANGLE = Math.PI / 3;
function isColliding(ballX, ballY, ballSize, paddleX, paddleY, paddleWidth, paddleHeight) {
    return (ballX < paddleX + paddleWidth &&
        ballX + ballSize > paddleX &&
        ballY < paddleY + paddleHeight &&
        ballY + ballSize > paddleY);
}
function computeImpact(ballY, ballSize, paddleY, paddleHeight) {
    const ballCenter = ballY + ballSize / 2;
    const paddleCenter = paddleY + paddleHeight / 2;
    const relative = (ballCenter - paddleCenter) / (paddleHeight / 2);
    return Math.max(-1, Math.min(1, relative));
}
function applyBounce(impact, direction) {
    const speed = Math.hypot(ball.vx, ball.vy);
    const angle = impact * MAX_BOUNCE_ANGLE;
    ball.vx = speed * Math.cos(angle) * direction;
    ball.vy = speed * Math.sin(angle);
}
const paddleleft = {
    y: 200,
    speed: 5,
};
const paddleright = {
    y: 200,
    speed: 5,
};
const ball = {
    x: 350,
    y: 200,
    vx: 4,
    vy: 3,
    size: 14,
};
const keys = {
    ArrowUp: false,
    ArrowDown: false,
    w: false,
    s: false,
};
let animationId = null;
let gameRunning = false;
function onKeyDown(e) {
    if (e.key in keys) {
        keys[e.key] = true;
    }
}
function onKeyUp(e) {
    if (e.key in keys) {
        keys[e.key] = false;
    }
}
let debug = true;
function resetBall(field) {
    ball.x = field.clientWidth / 2 - ball.size / 2;
    ball.y = field.clientHeight / 2 - ball.size / 2;
    ball.vx = (Math.random() > 0.5 ? 4 : -4);
    ball.vy = (Math.random() > 0.5 ? 3 : -3);
}
function gameLoop(match) {
    const field = document.querySelector(".pong-field");
    const paddleElleft = document.querySelector(".paddle-left");
    const paddleElright = document.querySelector(".paddle-right");
    const ballEl = document.querySelector(".ball");
    const scoreLeftEl = document.getElementById("score-left");
    const scoreRightEl = document.getElementById("score-right");
    if (!field || !paddleElleft || !paddleElright || !ballEl)
        return;
    const fieldWidth = field.clientWidth;
    const fieldHeight = field.clientHeight;
    const paddleHeight = paddleElleft.clientHeight;
    const paddleWidth = paddleElleft.clientWidth;
    if (keys.w)
        paddleleft.y -= paddleleft.speed;
    if (keys.s)
        paddleleft.y += paddleleft.speed;
    if (keys.ArrowUp)
        paddleright.y -= paddleright.speed;
    if (keys.ArrowDown)
        paddleright.y += paddleright.speed;
    const minY = 0;
    const maxY = fieldHeight - paddleHeight;
    paddleleft.y = Math.max(minY, Math.min(maxY, paddleleft.y));
    paddleright.y = Math.max(minY, Math.min(maxY, paddleright.y));
    paddleElleft.style.top = `${paddleleft.y}px`;
    paddleElright.style.top = `${paddleright.y}px`;
    ball.x += ball.vx;
    ball.y += ball.vy;
    if (ball.y <= 0) {
        ball.y = 0;
        ball.vy *= -1;
    }
    if (ball.y + ball.size >= fieldHeight) {
        ball.y = fieldHeight - ball.size;
        ball.vy *= -1;
    }
    if (isColliding(ball.x, ball.y, ball.size, paddleElleft.offsetLeft, paddleleft.y, paddleWidth, paddleHeight)) {
        const impact = computeImpact(ball.y, ball.size, paddleleft.y, paddleHeight);
        applyBounce(impact, 1);
        ball.x = paddleElleft.offsetLeft + paddleWidth;
    }
    if (isColliding(ball.x, ball.y, ball.size, paddleElright.offsetLeft, paddleright.y, paddleWidth, paddleHeight)) {
        const impact = computeImpact(ball.y, ball.size, paddleright.y, paddleHeight);
        applyBounce(impact, -1);
        ball.x = paddleElright.offsetLeft - ball.size;
    }
    if (ball.x <= 0 || ball.x + ball.size >= fieldWidth) {
        resetBall(field);
        if (ball.x <= 0) {
            console.log("Point for Left Player");
            match.scoreBoard.player1Score += 1;
        }
        else {
            console.log("Point for Right Player");
            match.scoreBoard.player2Score += 1;
        }
    }
    if (scoreLeftEl && scoreRightEl) {
        scoreLeftEl.textContent = match.scoreBoard.player1Score.toString();
        scoreRightEl.textContent = match.scoreBoard.player2Score.toString();
    }
    ballEl.style.left = `${ball.x}px`;
    ballEl.style.top = `${ball.y}px`;
    if (match.scoreBoard.player1Score >= match.nb) {
        gameRunning = false;
        match.scoreBoard.winner = match['player1'];
        console.log(`Match Over, ${match.scoreBoard.winner.alias} won the game.`);
        return;
    }
    if (match.scoreBoard.player2Score >= match.nb) {
        gameRunning = false;
        match.scoreBoard.winner = match['player2'];
        console.log(`Match Over, ${match.scoreBoard.winner.alias} won the game.`);
        return;
    }
    animationId = requestAnimationFrame(() => gameLoop(match));
}
export const MatchPage = {
    render() {
        return `
			<section class="pong-container">
				<div class="score">
					<span id="score-left">0</span>
					<span>:</span>
					<span id="score-right">0</span>
				</div>

				<div class="pong-field">
					<div class="net"></div>

					<div id="paddle-left" class="paddle paddle-left"></div>
					<div class="paddle paddle-right"></div>

					<div class="ball"></div>
				</div>

				<div class="controls">
					<button id="start-match">Start Match</button>
					<a href="/" data-link>Back</a>
				</div>
			</section>
		`;
    },
    onMount() {
        const field = document.querySelector(".pong-field");
        const paddleElleft = document.querySelector(".paddle-left");
        const paddleElright = document.querySelector(".paddle-right");
        const ballEl = document.querySelector(".ball");
        if (field && paddleElleft && paddleElright && ball) {
            paddleleft.y = (field.clientHeight - paddleElleft.clientHeight) / 2;
            paddleright.y = (field.clientHeight - paddleElright.clientHeight) / 2;
            paddleElright.style.top = `${paddleright.y}px`;
            paddleElleft.style.top = `${paddleleft.y}px`;
            ball.x = field.clientWidth / 2 - ball.size / 2;
            ball.y = field.clientHeight / 2 - ball.size / 2;
            ballEl.style.left = `${ball.x}px`;
            ballEl.style.top = `${ball.y}px`;
        }
        console.log("🎮 Match mounted");
        const btn = document.getElementById("start-match");
        if (!btn)
            return;
        window.addEventListener("keydown", onKeyDown);
        window.addEventListener("keyup", onKeyUp);
        btn.addEventListener("click", () => {
            if (gameRunning)
                return;
            gameRunning = true;
            gameState.mode = "match";
            const p1 = createPlayer("Alice", false);
            const p2 = createPlayer("Bob", false);
            const match = new Match(p1, p2);
            console.log("Match logic ready", match);
            gameLoop(match);
        });
    },
    onUnmount() {
        console.log("🧹 Match unmounted");
        gameRunning = false;
        window.removeEventListener("keydown", onKeyDown);
        window.removeEventListener("keyup", onKeyUp);
        if (animationId !== null) {
            cancelAnimationFrame(animationId);
            animationId = null;
        }
    },
};
