import { pool } from "../config/db";
import { User } from "../models/user.model";
import { RowDataPacket } from "mysql2";

interface UserRow extends User, RowDataPacket {}

class UserRepository {
  async create(user: User): Promise<number> {
    const { email, password, name, firstname } = user;
    const [result]: any = await pool.query(
      "INSERT INTO user (email, password, name, firstname) VALUES (?, ?, ?, ?)",
      [email, password, name, firstname]
    );
    return result.insertId;
  }
  async findByEmail(email: string): Promise<User | null> {
    const [rows] = await pool.query<UserRow[]>(
      "SELECT * FROM user WHERE email = ?",
      [email]
    );
    return rows[0] || null;
  }
}

export default new UserRepository();
