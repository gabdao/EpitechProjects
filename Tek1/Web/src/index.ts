// app.ts
import express, { Request, Response } from "express";
import dotenv from "dotenv";
dotenv.config();
import { ConnectToDatabase } from "./config/db";
import accountRoutes from "./routes/account.routes";
import usersRoutes from "./routes/users.routes";
import todosRoutes from "./routes/todo.routes";
import { verifyToken } from "./middleware/auth";

const app = express();
const PORT = process.env.PORT;

app.use(express.json());

app.use("/", accountRoutes); //end point handling register , login, /user and /user/todos
app.use("/users", verifyToken, usersRoutes); //endpoints handling users protected
app.use("/todos", verifyToken, todosRoutes); //endpoints handling todos protected

ConnectToDatabase()
  .then(() => {
    app.listen(PORT, () => console.log("server opened at port:", PORT));
  })
  .catch((err) => {
    console.log("Error occured from mysql connection error :", err);
    process.exit(0);
  });