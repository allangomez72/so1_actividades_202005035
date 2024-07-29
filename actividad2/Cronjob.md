# ¿Cómo crear un cronjob?

Para crear el cronjob se debe ejecutar el comando en la terminal.

```sh
crontab -e
```

Y luego ya se puede editar ya sea con nano o vim, independientemente del editor que se use se agrega en la ultima linea lo siguiente:

```sh
*/5 * * * * /rutadondeestaelscript/actividad2.sh
```
Y luego se guarda y se sale del editor y con eso ya se estara ejecutando automaticamente el script

Para visualizar lo que contiene el script, se puede usar cat
```sh
cat /tmp/<fecha>/saludos.log
```