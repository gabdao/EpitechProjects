export interface Todo {
    id?: number;
    title: string;
    description: string;
    due_time: string;
    status?: "not started" | "todo" | "in progress" | "done";
    user_id: number;
    created_at?: string;
  }
  