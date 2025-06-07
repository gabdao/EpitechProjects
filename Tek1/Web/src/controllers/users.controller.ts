import { Request, Response } from "express";
import UserRepository from "../repositories/users.repository";

export const getAllUsers = async (req: Request, res: Response) => {
  try {
    const users = await UserRepository.findAll();
    res.status(200).json(users);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const getUserById = async (req: Request, res: Response) => {
  try {
    const id = parseInt(req.params.id);
    const user = await UserRepository.findById(id);

    if (!user) {
      res.status(404).json({ msg: "Not found" });
      return;
    }
    res.status(200).json(user);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const updateUser = async (req: Request, res: Response) => {
  try {
    const id = parseInt(req.params.id);
    const updated_user = await UserRepository.update(id, req.body);

    if (!updated_user) {
      res.status(404).json({ msg: "Not found" });
      return;
    }

    res.status(200).json(updated_user);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const deleteUser = async (req: Request, res: Response) => {
  try {
    const id = parseInt(req.params.id);
    const deleted_user = await UserRepository.delete(id);

    if (!deleted_user) {
      res.status(404).json({ msg: "Not found" });
      return;
    }
    res.status(200).json({ msg: `Successfully deleted record number: ${id}` });
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};
