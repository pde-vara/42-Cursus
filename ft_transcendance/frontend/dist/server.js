// import Fastify from "fastify";
// import { db } from "./backend/src/db/sqlite";
export {};
// const app = Fastify({ logger: true });
// /* REGISTER */
// app.post("/auth/register", async (req, reply) => {
// 	const { email, password } = req.body as {
// 		email: string;
// 		password: string;
// 	};
// 	if (!email || !password) {
// 		return reply.code(400).send({ error: "Missing fields" });
// 	}
// 	db.run(
// 		"INSERT INTO users (alias) VALUES (?)",
// 		[email],
// 		function (err) {
// 			if (err) {
// 				return reply.code(500).send({ error: err.message });
// 			}
// 			reply.send({ success: true, userId: this.lastID });
// 		}
// 	);
// });
// /* LOGIN */
// app.post("/auth/login", async (req, reply) => {
// 	const { email } = req.body as { email: string };
// 	db.get(
// 		"SELECT * FROM users WHERE alias = ?",
// 		[email],
// 		(err, user) => {
// 			if (!user) {
// 				return reply.code(401).send({ error: "Invalid credentials" });
// 			}
// 			reply.send({ success: true, user });
// 		}
// 	);
// });
// app.listen({ port: 3000, host: "0.0.0.0" });
