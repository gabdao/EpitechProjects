import express from "express";
import {
  registerUser,
  loginUser,
  getMyProfile,
  getMyTodos,
} from "../controllers/account.controller";
import { verifyToken } from "../middleware/auth";

const router = express.Router();

router.post("/register", registerUser); // POST /user/register
router.post("/login", loginUser); // POST /user/login

router.get("/user", verifyToken, getMyProfile); // GET /user protected
router.get("/user/todos", verifyToken, getMyTodos); // GET /user/todos protected

export default router;
