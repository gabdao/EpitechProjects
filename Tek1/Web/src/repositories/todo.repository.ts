import { pool } from "../config/db";
import { Todo } from "../models/todo.model";
import { RowDataPacket } from "mysql2";

interface TodoRow extends Todo, RowDataPacket {}

class TodoRepository {
  async findAll(): Promise<Todo[]> {
    const [rows] = await pool.query<TodoRow[]>("SELECT * FROM todo");
    return rows;
  }

  async findById(id: number): Promise<Todo | null> {
    const [rows] = await pool.query<TodoRow[]>(
      "SELECT * FROM todo WHERE id = ?",
      [id]
    );
    return rows[0] || null;
  }

  async findByUserId(id: number): Promise<Todo | null> {
    const [rows] = await pool.query<TodoRow[]>(
      "SELECT * FROM todo WHERE user_id = ?",
      [id]
    );
    return rows[0] || null;
  }

  async create(todo: Todo): Promise<Todo> {
    const { title, description, due_time, user_id } = todo;

    const [result]: any = await pool.query(
      "INSERT INTO todo (title, description, due_time, user_id) VALUES (?, ?, ?, ?)",
      [title, description, due_time, user_id]
    );
    const insertId = result.insertId;
    const [rows] = await pool.query<TodoRow[]>(
      "SELECT * FROM todo WHERE id = ?",
      [insertId]
    );
    return rows[0];
  }

  async update(id: number, todo: Partial<Todo>): Promise<Todo | null> {
    const { title, description, due_time, status, user_id } = todo;
    const [result]: any = await pool.query(
      `UPDATE todo SET title = ?, description = ?, due_time = ?, status = ?, user_id = ? WHERE id = ?`,
      [title, description, due_time, status, user_id, id]
    );
    if (result.affectedRows === 0) return null;
    const [rows] = await pool.query<TodoRow[]>(
      "SELECT * FROM todo WHERE id = ?",
      [id]
    );
    return rows[0] || null;
  }

  async delete(id: number): Promise<boolean> {
    const [result]: any = await pool.query("DELETE FROM todo WHERE id = ?", [
      id,
    ]);
    return result.affectedRows > 0;
  }
}

export default new TodoRepository();
