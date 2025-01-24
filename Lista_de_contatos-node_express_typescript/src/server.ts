import express from "express";
import helmet from "helmet"
import router from "./routes";
import path from "path";

const server = express();
server.use(helmet());
server.use(express.json());
server.use(express.static(path.join(__dirname, "../public")));

server.use("/", router)

server.listen(3000, () => {

    console.log("Servidor funcionando em http://localhost:3000");
})