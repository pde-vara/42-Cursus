import {} from "../models/pageType.js";
import { navigateTo } from "../router.js";
export const RegisterPage = {
    render: () => `
    <h1>Register</h1>
    <form id="registerForm" class="flex flex-col gap-2 max-w-sm">
      <input type="email" name="email" placeholder="Email" required class="p-2 rounded border" />
      <input type="text" name="username" placeholder="Username" required class="p-2 rounded border" />
      <input type="password" name="password" placeholder="Password" required class="p-2 rounded border" />
      <button type="submit" class="bg-blue-500 text-white p-2 rounded hover:bg-blue-600">Register</button>
    </form>
    <div id="registerError" class="text-red-500 mt-2"></div>
    <p class="mt-2">Already have an account? <a data-link href="/login" class="text-blue-400 hover:underline">Login</a></p>
  `,
    onMount: () => {
        const form = document.getElementById("registerForm");
        form.addEventListener("submit", async (e) => {
            e.preventDefault();
            const formData = new FormData(form);
            const email = formData.get("email");
            const username = formData.get("username");
            const password = formData.get("password");
            try {
                const res = await fetch("/auth/register", {
                    method: "POST",
                    headers: { "Content-Type": "application/json" },
                    body: JSON.stringify({ email, username, password }),
                    credentials: "include"
                });
                if (res.ok) {
                    navigateTo("/login"); // redirige vers la page login
                }
                else {
                    const error = await res.json();
                    const errorDiv = document.getElementById("registerError");
                    errorDiv.textContent = error.message || "Erreur lors de l'inscription";
                }
            }
            catch (err) {
                const errorDiv = document.getElementById("registerError");
                errorDiv.textContent = "Impossible de contacter le serveur";
            }
        });
    }
};
