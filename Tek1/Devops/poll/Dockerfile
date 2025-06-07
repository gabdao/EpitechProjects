# 1. python image
FROM python:3.11-slim

# 2. working directory
WORKDIR /app

# 3. retrieve app files
COPY . .

# 4. install dependecies with pip
RUN pip install --no-cache-dir -r requirements.txt

# 5. expose port 80
EXPOSE 80

# 6. run app with commands
CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]
