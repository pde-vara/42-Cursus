function getRand() {
    const dateStr = Date.now().toString();
    const random = Math.random().toString(36).substring(2, 8);
    return `${dateStr}-${random}`;
}
function sideRand() {
    if (Math.random() > 0.5)
        return "right";
    return "left";
}
export function createPlayer(alias, bot) {
    const newplayer = { alias: alias, id: getRand(), score: 0, isBot: bot, side: sideRand() };
    return newplayer;
}
