import { createPlayer } from "../models/player.js";
export class Match {
    player1;
    player2;
    nb = 3;
    scoreBoard;
    constructor(player1, player2) {
        this.player1 = player1;
        this.player2 = player2;
        this.scoreBoard = {
            player1Score: 0,
            player2Score: 0,
            winner: createPlayer("temp", false),
        };
    }
    matchStart() {
        if (this.scoreBoard.winner.alias !== "temp")
            return this.scoreBoard.winner;
        else
            return createPlayer("temp", false);
    }
}
;
