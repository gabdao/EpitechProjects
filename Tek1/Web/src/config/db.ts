import { createPool } from "mysql2/promise";

const pool = createPool({
  port: parseInt(process.env.DB_PORT || "3306"),
  host: process.env.MYSQL_HOST || "localhost",
  user: process.env.MYSQL_USER || "user_random",
  password: process.env.MYSQL_PASSWORD || "",
  database: process.env.MYSQL_DATABASE || "",
});

const ConnectToDatabase = async () => {
  const connection = await pool.getConnection();
  connection.release();
};

export { ConnectToDatabase, pool };
