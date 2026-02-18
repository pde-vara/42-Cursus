import { Match } from "./match.js";
import { createPlayer } from "../models/player.js";
export class Tournament {
    players;
    nb;
    constructor(nb) {
        this.nb = nb;
        let i = 0;
        this.players = [];
        for (let i = 0; i < nb; i++)
            this.players.push(createPlayer("Player" + (i + 1).toString(), false));
    }
    startTournament() {
        let currentPlayers = [...this.players];
        let round = 1;
        while (currentPlayers.length > 1) {
            console.log(`\n=== ROUND ${round}===\n`);
            currentPlayers = this.playRound(currentPlayers);
            round++;
        }
        return currentPlayers[0];
    }
    playRound(players) {
        const winners = [];
        for (let i = 0; i < players.length; i += 2) {
            const player1 = players[i];
            const player2 = players[i + 1];
            if (!player2) {
                winners.push(player1);
                continue;
            }
            const match = new Match(player1, player2);
            const winner = match.matchStart();
            winners.push(winner);
        }
        return winners;
    }
    reset() {
        this.players = [];
    }
}
;
