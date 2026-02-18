import { HomePage } from "./_pages/home.js";
import { MatchPage } from "./_pages/match.js";
import { TournamentPage } from "./_pages/tournament.js";
import { LoginPage } from "./_pages/login.js";
import { RegisterPage } from "./_pages/register.js";
import {} from "./models/pageType.js";
import {} from "./store/gameState.js";
let currentPage = null;
export const gameState = {
    mode: null,
    winner: null,
    tournamentRunning: false
};
const routes = {
    "/": HomePage,
    "/home": HomePage,
    "/tournament": TournamentPage,
    "/match": MatchPage,
    "/login": LoginPage,
    "/register": RegisterPage
};
function getRoute(pathname) {
    if (routes[pathname])
        return routes[pathname];
    return routes["/"];
}
export function router() {
    const currentPath = window.location.pathname;
    const renderPages = getRoute(currentPath);
    const app = document.getElementById("app");
    if (!app) {
        console.error("Routeur: #app introuvable dans le DOM");
        return;
    }
    if (currentPage && currentPage.onUnmount) {
        currentPage.onUnmount();
    }
    app.innerHTML = renderPages.render();
    if (renderPages.onMount) {
        renderPages.onMount();
    }
    currentPage = renderPages;
}
export function navigateTo(href) {
    if (window.location.pathname === href) {
        router();
        return;
    }
    history.pushState({}, "", href);
    router();
}
