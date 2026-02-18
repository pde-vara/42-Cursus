import {} from "../models/pageType.js";
export const HomePage = {
    render() {
        return `
        <h1>Home</h1>
        <p>Bienvenue dans ft_transcendance</p>
		<p>Please select a mode :</p>
		<ul>
        	<li><a href="/tournament" data-link>Voir le tournoi</a></li>
			<li><a href="/match" data-link>Jouer un match</a></li>
			<li><a href="/login" data-link>Login</a></li>
			<li><a href="/register" data-link>Register</a></li>
		</ul>
    `;
    },
};
