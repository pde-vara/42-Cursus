# 🕹️ Transcendence — Backend (Mandatory)

## 📌 Présentation

Ce backend implémente le **cœur logique du projet Transcendence (mandatory)** :

- gestion des joueurs (alias)
- création de tournois
- inscription des joueurs à un tournoi
- génération automatique des matchs (round-robin)
- persistance des données via SQLite
- API HTTP avec Fastify

Le choix a été fait de privilégier une **architecture simple, claire et défendable**, sans sur‑ingénierie.

---

## 🧱 Stack technique

- Node.js
- TypeScript
- Fastify
- SQLite
- sqlite3

---

## 📂 Architecture du projet

```
backend/
├─ src/
│  ├─ server.ts              # Démarrage du serveur Fastify
│  │
│  ├─ routes/                # Couche HTTP
│  │  ├─ users.ts
│  │  └─ tournaments.ts
│  │
│  ├─ services/              # Logique métier / SQL
│  │  ├─ userService.ts
│  │  ├─ tournamentService.ts
│  │  ├─ tournamentPlayerService.ts
│  │  └─ matchService.ts
│  │
│  └─ db/
│     └─ sqlite.ts            # Connexion SQLite
│
├─ tsconfig.json
└─ package.json
```

### Principes
- Routes = HTTP uniquement
- Services = logique métier + SQL
- Aucune requête SQL dans les routes
- Aucun Fastify dans les services

---

## 🗄️ Schéma de la base de données

### users
```sql
id INTEGER PRIMARY KEY
alias TEXT NOT NULL
```

### tournaments
```sql
id INTEGER PRIMARY KEY
created_at DATETIME NOT NULL
```

### tournament_players
```sql
tournament_id INTEGER
user_id INTEGER
PRIMARY KEY (tournament_id, user_id)
```

### matches
```sql
id INTEGER PRIMARY KEY
tournament_id INTEGER
created_at DATETIME
```

### match_players
```sql
match_id INTEGER
user_id INTEGER
PRIMARY KEY (match_id, user_id)
```

Toutes les relations sont protégées par des **FOREIGN KEY**.

---

## 🔁 Logique de tournoi (Matchmaking)

### Type
**Round‑robin simple** : chaque joueur affronte tous les autres une fois.

### Déroulement
1. Création d’un tournoi
2. Création des joueurs
3. Inscription des joueurs au tournoi
4. Génération manuelle des matchs
5. Tous les matchs sont connus dès le départ

Nombre de matchs :
```
n * (n - 1) / 2
```

---

## 🌐 Endpoints API

### Healthcheck
```
GET /health
→ { "ok": true }
```

### Users

Créer un joueur :
```
POST /users
Body: { "alias": "alice" }
```

Lister les joueurs (debug) :
```
GET /users
```

### Tournaments

Créer un tournoi :
```
POST /tournaments
```

Inscrire un joueur :
```
POST /tournaments/:id/players
Body: { "userId": 1 }
```

Générer les matchs :
```
POST /tournaments/:id/generate-matches
```

---

## ▶️ Lancer le projet

```bash
npm install
npx ts-node src/server.ts
```

Serveur disponible sur :
```
http://localhost:3000
```


## ✅ État

✔ Mandatory backend terminé  
✔ Architecture propre  
✔ DB cohérente  
✔ Matchmaking fonctionnel  
