# EpyTodo

EpyTodo is a REST API for a todo list application. It provides user management and task handling through secure CRUD endpoints protected by JWT authentication.

## Technologies Used
- Node.js
- Express.js
- MySQL (`mysql2`)
- JWT (`jsonwebtoken`)
- `bcrypt`
- `dotenv`

## Usage

### 1. Clone the repository
```bash
git clone git@github.com:EpitechPGEPromo2029/B-WEB-200-PAR-2-1-epytodo-gabriel2.daouk.git
```

### 2. Install dependencies
```bash
npm install
```

### 3. Create a .env file
```bash
MYSQL_DATABASE=epytodo
MYSQL_USER=root
MYSQL_PASSWORD=your_password
MYSQL_HOST=127.0.0.1
PORT=3000
SECRET=your_jwt_secret
```

### 4. Configure the database
```bash
cd src/config
docker-compose up -d
```

### 5. Start the server
```bash
npm start
```
