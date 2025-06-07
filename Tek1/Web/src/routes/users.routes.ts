import express from "express";
import {
  getAllUsers,
  getUserById,
  updateUser,
  deleteUser,
} from "../controllers/users.controller";

const router = express.Router();

router.get("/", getAllUsers); //view all users (bonus)
router.get("/:id", getUserById); //view specific user information (mandatory)
router.put("/:id", updateUser); //update user information (mandatory)
router.delete("/:id", deleteUser); //Delete User (mandatory)

export default router;
