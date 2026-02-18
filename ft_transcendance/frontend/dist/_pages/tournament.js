import { Match } from "../game/match.js";
import { createPlayer } from "../models/player.js";
import { Tournament } from "../game/tournament.js";
import {} from "../models/pageType.js";
import { gameState } from "../router.js";
export const TournamentPage = {
    render() {
        return `
			<h1>Tournoi</h1>
			<button id="start-tournament">Lancer le tournoi</button>
			<pre id="result"></pre>
			<a href="/" data-link>Retour</a>
		`;
    },
    onMount() {
        const btn = document.getElementById("start-tournament");
        const result = document.getElementById("result");
        if (!btn)
            return;
        if (!result)
            return;
        gameState.mode = "tournament";
        gameState.tournamentRunning = true;
        btn.addEventListener("click", () => {
            const Tournoi = new Tournament(6);
            const winner = Tournoi.startTournament();
            gameState.winner = winner.alias;
            result.innerText = `Le gagnant du tournoi est : ${winner.alias}`;
        });
        gameState.tournamentRunning = false;
        gameState.mode = null;
        gameState.winner = null;
    }
};
