#!/bin/bash
#GUARDAR EL NOMBRE DE USUARIO DE GITHUB EN UNA VARIABLE
#echo "Ingresar usuario de GITHUB"
#read GITHUB_USER

GITHUB_USER=$1

#consultar el link para los valores
response=$(wget -qO- https://api.github.com/users/$GITHUB_USER)

#guardar los valores en variables
githubuser=$(echo "$response" | grep -oP '"login": "\K[^"]+')
id=$(echo "$response" | grep -oP '"id": \K\d+')
created_at=$(echo "$response" | grep -oP '"created_at": "\K[^"]+')

#imprimir el mensaje
mensaje="Hola $githubuser. User ID: $id. Cuenta fue creada el: $created_at"
echo $mensaje

fecha=$(date +%Y-%m-%d)
mkdir -p /tmp/$fecha
echo $mensaje >> /tmp/$fecha/saludos.log