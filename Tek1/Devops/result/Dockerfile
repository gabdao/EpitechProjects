# Alpine image
FROM node:20-alpine

#Working directory
WORKDIR /app

#Retriebe app files
COPY . .

#Install dependecies
RUN npm install

#Expose port
EXPOSE 80

#RUn app
CMD ["npm", "start"]
