import { pool } from "../config/db";
import { User } from "../models/user.model";
import { RowDataPacket } from "mysql2";

interface UserRow extends User, RowDataPacket {}

class UserRepository {
  async findAll(): Promise<User[]> {
    const [rows] = await pool.query<UserRow[]>("SELECT * FROM user");
    return rows;
  }

  async findById(id: number): Promise<User | null> {
    const [rows] = await pool.query<UserRow[]>(
      "SELECT * FROM user WHERE id = ?",
      [id]
    );
    return rows[0] || null;
  }

  async update(id: number, user: Partial<User>): Promise<User | null> {
    const { email, password, name, firstname } = user;

    const [result]: any = await pool.query(
      `UPDATE user SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?`,
      [email, password, name, firstname, id]
    );

    if (result.affectedRows === 0) return null;

    const [rows] = await pool.query<UserRow[]>(
      "SELECT * FROM user WHERE id = ?",
      [id]
    );

    return rows[0] || null;
  }

  async delete(id: number): Promise<boolean> {
    const [result]: any = await pool.query("DELETE FROM user WHERE id = ?", [
      id,
    ]);
    return result.affectedRows > 0;
  }
}

export default new UserRepository();
