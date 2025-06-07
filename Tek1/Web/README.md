# Epytodo

EpyTodo est une API REST pour une todo list. Elle permet la gestion d'utilisateurs et de leurs tâches à travers des endpoints CRUD sécurisés par JWT.  

## Technologies utilisés

- Node.js
- Express.js
- MySQL (`mysql2`)
- JWT (`jsonwebtoken`)
- `bcrypt`
- `dotenv`

## Usage

### 1 Cloner le répôt
```bash
git clone git@github.com:EpitechPGEPromo2029/B-WEB-200-PAR-2-1-epytodo-gabriel2.daouk.git
```
### 2 Installer les dépendances
```bash
npm install
```
### 3 Créer un .env
```bash
MYSQL_DATABASE=epytodo
MYSQL_USER=root
MYSQL_PASSWORD=your_password
MYSQL_HOST=127.0.0.1
PORT=3000
SECRET=your_jwt_secret
```
### 4 Configurer la databse
```bash
cd src/config
docker-compose up -d
```
### 5 Lancer le serveur
```bash
npm start
```
