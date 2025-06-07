import express from "express";
import {
  getAllTodos,
  getTodoById,
  createTodo,
  updateTodo,
  deleteTodo,
} from "../controllers/todo.controller";

const router = express.Router();

// "/todos/"

router.get("/", getAllTodos); //view all the todos (mandatory)
router.get("/:id", getTodoById); //view specific to do (mandatory)
router.post("/", createTodo); //create to do (mandatory)
router.put("/:id", updateTodo); //update to do (mandatory)
router.delete("/:id", deleteTodo); //Delete to do (mandatory)

export default router;
