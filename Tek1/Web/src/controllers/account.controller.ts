import { Request, Response } from "express";
import accountRepository from "../repositories/account.repository";
import usersRepository from "../repositories/users.repository";
import todoRepository from "../repositories/todo.repository";
import { User } from "../models/user.model";
import { AuthRequest } from "../middleware/auth";
import bcrypt from "bcrypt"
import jwt from "jsonwebtoken";

const SECRET = process.env.SECRET;


export const registerUser = async (req: Request, res: Response) => {
  const newUser: User = req.body;
  if (
    !newUser.email ||
    !newUser.name ||
    !newUser.firstname ||
    !newUser.password
  ) {
    res.status(400).json({ msg: "Bad Parameter" });
    return;
  }
  try {
    const existingUser = await accountRepository.findByEmail(newUser.email);
    if (existingUser) {
      res.status(409).json({ msg: "Account already exists" });
      return;
    }
    newUser.password = await bcrypt.hash(newUser.password, 10);
    const insertId = await accountRepository.create(newUser);
    const token = jwt.sign({ id: insertId }, SECRET, { expiresIn: "2h" });
    res.status(201).json({ id: insertId, message: "User created", token: token });
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const loginUser = async (req: Request, res: Response) => {
  const { email, password } = req.body;

  if (!email || !password) {
    res.status(400).json({ msg: "Bad parameter" });
    return;
  }

  try {
    const user = await accountRepository.findByEmail(email);
    if (!user) {
      res.status(401).json({ msg: "Invalid credentials" });
      return;
    }
    const verifylogin = await bcrypt.compare(password, user.password);
    if (!verifylogin) {
      res.status(401).json({ msg: "Invalid credentials" });
      return;
    }

    const token = jwt.sign({ id: user.id }, SECRET, { expiresIn: "2h" });

    res.status(200).json({
      message: "Login successful",
      token,
      user: {
        id: user.id,
        email: user.email,
        name: user.name,
        firstname: user.firstname,
        created_at: user.created_at,
      },
    });
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const getMyProfile = async (req: AuthRequest, res: Response) => {
  const userId = req.user.id;

  // console.log(userId);
  if (!userId) {
    res.status(401).json({ msg: "Bad parameter" });
    return;
  }

  try {
    const user = await usersRepository.findById(userId);
    if (!user) {
      res.status(404).json({ msg: "Not found" });
      return;
    }
    res.status(200).json({
      id: user.id,
      email: user.email,
      password: user.password,
      created_at: user.created_at,
      firstname: user.firstname,
      name: user.name,
    });
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};

export const getMyTodos = async (req: AuthRequest, res: Response) => {
  const userId = req.user.id;

  if (!userId) {
    res.status(401).json({ msg: "Bad parameter" });
    return;
  }

  try {
    const todos = await todoRepository.findByUserId(userId);
    if (!todos) {
      res.status(400).json({ msg: "Not found"});
    }
    res.status(200).json(todos);
  } catch (err) {
    res.status(500).json({ msg: "Internal server error" });
  }
};
