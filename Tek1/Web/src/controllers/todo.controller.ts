import { Request, Response } from "express";
import todoRepository from "../repositories/todo.repository";
import { Todo } from "../models/todo.model";

export const getAllTodos = async (req: Request, res: Response) => {
  try {
    const todos = await todoRepository.findAll();
    res.status(200).json(todos);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const getTodoById = async (req: Request, res: Response) => {
  try {
    const id = parseInt(req.params.id);
    const todo = await todoRepository.findById(id);

    if (!todo) {
      res.status(404).json({ msg: "Not found" });
      return;
    }
    res.status(200).json(todo);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const createTodo = async (req: Request, res: Response) => {
  try {
    const newTodo: Todo = req.body;
    const todo = await todoRepository.create(newTodo);

    res.status(201).json(todo);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const updateTodo = async (req: Request, res: Response) => {
  try {
    const id = parseInt(req.params.id);
    const updated_todo = await todoRepository.update(id, req.body);

    if (!updated_todo) {
      res.status(404).json({ msg: "Not found" });
      return;
    }
    res.status(200).json(updated_todo);
  } catch (err) {
    console.log("error");
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const deleteTodo = async (req: Request, res: Response) => {
  try {
    const id = parseInt(req.params.id);
    const deleted = await todoRepository.delete(id);

    if (!deleted) {
      res.status(404).json({ msg: "Not found" });
      return;
    }
    res.status(200).json({ msg: `Successfully deleted record number: ${id}` });
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};
