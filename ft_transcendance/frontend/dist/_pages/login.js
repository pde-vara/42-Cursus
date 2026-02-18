import {} from "../models/pageType.js";
import { navigateTo } from "../router.js"; // pour naviguer après login
// Définition de la page Login
export const LoginPage = {
    // La fonction render retourne le HTML de la page
    render: () => `
		<h1>Login</h1>
		<form id="loginForm">
			<input type="email" name="email" placeholder="Email" required />
			<input type="password" name="password" placeholder="Password" required />
			<button type="submit">Login</button>
		</form>
		<div id="loginError"></div>

		<p>
			Pas encore de compte ?
			<a href="/register" data-link>Créer un compte</a>
		</p>
	`,
    // onMount est appelée automatiquement par le router quand la page est affichée
    onMount: () => {
        // On récupère le formulaire du DOM
        const form = document.getElementById("loginForm");
        // On écoute l'événement submit du formulaire
        form.addEventListener("submit", async (e) => {
            e.preventDefault(); // empêche le rechargement de la page
            // Récupère les données du formulaire
            const formData = new FormData(form);
            const email = formData.get("email");
            const password = formData.get("password");
            // On fait un appel HTTP au backend pour tenter de se connecter
            const res = await fetch("/auth/login", {
                method: "POST",
                headers: { "Content-Type": "application/json" },
                body: JSON.stringify({ email, password }),
                credentials: "include" // pour les cookies
            });
            if (res.ok) {
                navigateTo("/home"); // redirige vers Home après login
            }
            else {
                // Sinon on affiche un message d'erreur
                const errorDiv = document.getElementById("loginError");
                errorDiv.textContent = "Email ou mot de passe incorrect";
            }
        });
    }
};
