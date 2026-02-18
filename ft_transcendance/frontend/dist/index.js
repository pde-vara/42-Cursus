import { router, navigateTo } from "./router.js";
function handleClick(ev) {
    const target = ev.target; // Récupère l'élément cliqué
    if (!target)
        return;
    const anchor = target.closest("a[data-link]"); // Cherche le lien le plus proche avec data-link
    if (!anchor)
        return;
    if (ev.defaultPrevented) // Si le clic a déjà été annulé par un autre code, on ignore
        return;
    if (ev.button !== 0) // Ignore les clics qui ne sont pas le bouton gauche
        return;
    if (ev.metaKey || ev.ctrlKey || ev.shiftKey || ev.altKey) // Ignore les clics combinés avec Ctrl, Shift, Alt ou Cmd
        return;
    const href = anchor.getAttribute("href"); // Récupère l'URL du lien
    if (!href)
        return;
    // Si le lien est externe ou doit s'ouvrir dans un nouvel onglet, ne rien faire
    if (href.startsWith("http://") || href.startsWith("https://") || anchor.target === "_blank")
        return;
    ev.preventDefault(); // Empêche le navigateur de recharger la page
    navigateTo(href); // Navigation SPA vers l'URL sans rechargement
}
// Ajoute l'interception globale des clics sur les liens SPA
function setLinkInterception() {
    window.addEventListener("click", handleClick);
}
// Écoute le bouton "Précédent" / "Suivant" du navigateur pour mettre à jour la SPA
function setPopStateListener() {
    window.addEventListener("popstate", router);
}
function init() {
    router();
    setLinkInterception();
    setPopStateListener();
}
// Quand le HTML est complètement chargé, exécute l'initialisation
document.addEventListener("DOMContentLoaded", init);
