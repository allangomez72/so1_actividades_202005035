# GESTION DE USUARIOS, GRUPOS Y PERMISOS EN UN SO LINUX

## Parte 1: Gestión de usuarios
### 1. Creación de usuarios
```bash
sudo useradd -m usuario1
sudo useradd -m usuario2
sudo useradd -m usuario3
```

>[!IMPORTANT]
> Se usa el `-m` para crear el directorio principal del usuario
### 2. Asignacion de contraseñas
```bash
sudo passwd usuario1
```
Luego de ejecutar el comando se pedira la contraseña y se debe ingresar la contraseña deseada.
>[!NOTE]
> El comando `passwd` se debe ejecutar para cada usuario creado.

Al ser un ejemplo se usaran contraseñas simples, pero en un ambiente real se deben usar contraseñas seguras.

|Usuario| Contaseña    |
|-------|--------------|
|usuario1| contrasenia1 |
|usuario2| contrasenia2 |
|usuario3| contrasenia3 |

Cuando ya se haya seteado la contraseña para cada usuario el mensaje que se mostrara sera el siguiente:
```bash
passswd: password updated successfully
```

### 3. Información de los usuarios
Para ver la información de los usuarios se puede usar el comando `id`:
```bash
id usuario1
```
>[!NOTE]
> Pasa verificar la informacion de otros usuarios solo se cambia el nombre de `usuario1` por el user que se desea verificar.

Al ejecutar el comando se mostrara la siguiente información (No debe ser igual, puede variar algunas partes):
```bash
uid=1001(usuario1) gid=1001(usuario1) groups=1002(usuario1)
```
### 4. Eliminacion de Usuarios.
Para eliminar un usuario se debe ejecutar el siguiente comando:
```bash
sudo userdel usuario3
```
Con este comando se elimina el usuario, en este caso el usuario3, pero se conserva el directorio principal del usuario.

## Parte 2: Gestión de grupos
### 1. Creación de grupos
Para crear un grupo se debe ejecutar el siguiente comando:
```bash
sudo groupadd grupo1
sudo groupadd grupo2
```
En este caso como se ejecuto dos veces el comando `groupadd` se crearon dos grupos, `grupo1` y `grupo2`.

### 2. Asignación de usuarios a grupos.
Para este ejemplo se asignara el usuario1 al grupo1 y el usuario2 al grupo2.
1. 
```bash
sudo usermod -g grupo1 usuario1
sudo usermod -g grupo2 usuario2
```
### 3. Verificar membresía de grupos
Para verificar la membresía de un usuario a un grupo se puede usar el comando `groups`:
```bash
groups usuario1
```
>[!IMPORTANT]
> Si desea verificar la membresía de otro usuario solo se cambia el nombre de `usuario1` por el usuario que se desea verificar.

### 4. Eliminación de grupos
Para eliminar un grupo se debe ejecutar el siguiente comando:
```bash
sudo groupdel grupo2
```
## Parte 3: Gestion de permisos
### 1. Creación de archivos y directorios
Para crear los archivos y los directorios se debe de logear al usuario al cual se quiere crear los archivos y directorios, para ello se debe de
verficar que se haya logeado con el usuario deseado con el comando `whoami` o `id - un`, si no se ha logeado con el usuario deseado se debe de logear con el comando `su - usuario1`.

Una vez logeado con el usuario deseado se procede a crear los archivos y directorios con los siguientes comandos:
```bash
touch /home/usuario1/archivo1.txt
echo "Esto es la prueba del archivo1" > /home/usuario1/archivo1.txt

mkdir /home/usuario1/directorio1
touch /home/usuario1/directorio1/archivo2.txt
```

### 2. Verificar los permisos
Para verifica los permisos del archivo y directorio se usan los comandos `ls -l` y `ls -ld` respectivamente.

Al ser un ejemplo la ruta podria cambiar si es que en el paso anterior se uso otro usuario.
```bash
ls -l /home/usuario1/archivo1.txt
ls -ld /home/usuario1/directorio1
```

La salida de los comandos anteriores podria ser la siguiente:
```bash
-rw-r--r-- 1 usuario1 usuario1 30 ago  4 19:30 /home/usuario1/archivo1.txt
drwxr-xr-x 2 usuario1 usuario1 4096 ago  4 19:31 /home/usuario1/directorio1
```

### 3. Modificar Permisos usando `chmod` con Modo Numérico:
Para modificar los permisos de un archivo o directorio se usa el comando `chmod` seguido de los permisos que se desean asignar y el archivo o directorio al cual se le asignaran los permisos.
```bash
chmod 640 /home/usuario1/archivo1.txt
```
En este caso el 6 es para el usuario, el 4 es para el grupo y el 0 es para otros.

### 4. Modificar Permisos usando `chmod` con Modo Simbólico:
Como ahora es para el archivo2 se debe cambiar la ruta del archivo.
```bash
chmod u+x /home/usuario1/directorio1/archivo2.txt
```
En este caso el `u` es para el usuario, el `+x` es para agregar permisos de ejecución.

### 5. Cambiar el Grupo Propietario:
Para cambiar el grupo propietario de un archivo o directorio se usa el comando `chown` pero tambien se puede usar `chgrp` seguido del grupo al cual se le asignara el archivo o directorio.
El ejemplo sera cambiar el grupo propietario de `archivo2.txt` a `grupo1`.
```bash
chown :grupo1 /home/usuario1/directorio1/archivo2.txt
```
### 6. Configurar Permisos de Directorio:
Para configurar los permisos de un directorio se usa el comando `chmod` seguido de los permisos que se desean asignar y el directorio al cual se le asignaran los permisos.
```bash
chmod 740 /home/usuario1/directorio1
```
En este caso el 7 es para el usuario, el 4 es para el grupo y el 0 es para otros.

>[!TIP]
> Se usa la [representacion](https://meest.dev/blog/permisos-basicos-linux) decimal de los permisos 

### 7. Comprobación de Acceso:
Para comprobar el acceso a un archivo o directorio se usa el comando `ls -l` y `ls -ld` respectivamente.

Como en este caso se quiere ver que los permisos fueron aplicados correctamente, se debe de cambiar de usuario,
en este caso al `usuario2` y se debe de verificar que el usuario2 no tenga permisos para acceder al archivo1.txt y al directorio1.
```bash
su - usuario2
```

Una vez ya logueado se procede a verificar los permisos de los archivos y directorios.
```bash
cat /home/usuario1/archivo1.txt
cat /home/usuario1/directorio1/archivo2.txt
```
Y la salida esperada de los comandos anteriores seria:
```bash
cat: /home/usuario1/archivo1.txt: Permission denied
cat: /home/usuario1/directorio1/archivo2.txt: Permission denied
```
o su equivalente en español:
```bash
cat: /home/usuario1/archivo1.txt: Permiso denegado
cat: /home/usuario1/directorio1/archivo2.txt: Permiso denegado
```

### 8. Verificación Final:
Como se esta logeado con el usuario2 y se desea verificar los permisos y propietario de los archivos y directorio nuevamente se usa el comando `ls -l` y `ls -ld` respectivamente.
```bash
ls -l /home/usuario1/archivo1.txt
ls -l /home/usuario1/directorio1/archivo2.txt
ls -ld /home/usuario1/directorio1
```

La salida esperada de los comandos anteriores seria:
```bash
ls: cannot access '/home/usuario1/archivo1.txt': Permission denied
ls: cannot access '/home/usuario1/directorio1/archivo2.txt': Permission denied
ls: cannot access '/home/usuario1/directorio1': Permission denied
```

para ver una salida como esta:
```bash
-rw-r----- 1 usuario1 grupo1  30 Aug  4 19:30 /home/usuario1/archivo1.txt
```
se debe de logear con el usuario1 y ejecutar los comandos `ls -l` y `ls -ld` respectivamente.

------------

### Reflexión
- **¿Por qué es importante gestionar correctamente los usuarios y permisos en un sistema operativo?**
Por que al tener una buena gestion tanto de usuarios como de los permisos que se asignan, se garantiza la seguridad
y la privacidad de los datos. Todo esto contribuye a un control para sabesr quien puede acdeder, modificar y ejecutar archivos y directorios.
- **¿Qué otros comandos o técnicas conocen para gestionar permisos en Linux?**
1. `chown` para cambiar el propietario de archivos y directorios.
2. `touch` para crear archivos.
3. `echo` para escribir en archivos.
4. `su` para cambiar de usuario.
5. `whoami` para saber el usuario actual.
6. `chgrp` para cambiar el grupo propietario de archivos y directorios.
