# POPEYE

## Description
Docker containerization project implementing a multi-container web poll application with microservices architecture. The system demonstrates container orchestration using Docker and Docker Compose for a complete voting application stack.

## Objective
Implement a `POPEYE` project that must:
- Containerize a 5-component web polling application
- Create Docker images for Poll, Worker, and Result services
- Deploy infrastructure using Docker Compose
- Configure multi-tier networking and persistent storage

### Application Architecture
The voting application consists of:
1. **Poll**: Flask Python web app collecting votes and pushing to Redis queue
2. **Redis**: Message queue holding votes for processing
3. **Worker**: Java application consuming votes from Redis and storing in PostgreSQL
4. **PostgreSQL**: Database persistently storing vote data
5. **Result**: Node.js web app displaying voting results from database

### Docker Images Requirements
**Poll Image**:
- Based on official Python image
- Exposes port 80
- Dependencies installed via `pip3 install -r requirements.txt`
- Started with `flask run --host=0.0.0.0 --port=80`

**Result Image**:
- Based on Node.js 20 Alpine official image
- Exposes port 80
- Dependencies installed via `npm install`
- Excludes node_modules from build context

**Worker Image**:
- Multi-stage build process
- Stage 1: maven:3.9.6-eclipse-temurin-21-alpine for compilation
- Stage 2: eclipse-temurin:21-jre-alpine for runtime
- Builds with `mvn dependency:resolve` and `mvn package`

### Docker Compose Configuration
**Services**:
- `poll`: Builds poll image, maps host:5000 → container:80
- `redis`: Official Redis 7 image, exposes port 6379
- `worker`: Builds worker image with environment variables
- `db`: PostgreSQL 16 with schema initialization
- `result`: Builds result image, maps host:5001 → container:80

**Networks**:
- `poll-tier`: Poll ↔ Redis communication
- `result-tier`: Result ↔ Database communication
- `back-tier`: Worker ↔ Redis + Database communication

**Storage**:
- `db-data`: Named volume for PostgreSQL data persistence

## Constraints
- Language: Docker/Docker Compose configuration
- No ENTRYPOINT instruction usage
- Environment variables configured in docker-compose.yml only
- Automatic container restart on failure
- Services accessible at localhost:5000 (Poll) and localhost:5001 (Result)
- Database dependencies handled through proper service ordering
