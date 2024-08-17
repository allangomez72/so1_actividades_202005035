# Servicio de Saludo Infinito

Para realizar este servicio se ejecuta un script que imprime un saludo y la fecha actual de manera infinica, la pausa que tiene sera de un segundo.

## Instalación

1. **Crear el script**:
    - Guardar el siguiente contenido en la ubicacion que desee, ej: `/home/gomez/Documentos/so1_actividades_202005035/actividad4` y hacerlo ejecutable:
    
    ```bash
    #!/bin/bash

    while true; do
        echo "¡Hola! La fecha y hora actual es: $(date)"
        sleep 1
    done
    ```
¿Como se hace ejecutable?
```bash
chmod -x saludo.sh
```

2. **Crear el archivo de servicio**:
    - Guardar el siguiente contenido en `/etc/systemd/system/saludo.service`:
   - [saludo.service](actividad4.md)
3. **Habilitar y ejecutar el servicio**:
   1. Primero se debe recargar el demonio de systemd
   2. Luego se habilita el sevicio para que se inicie al arrancar el sistema
   3. Por ultimo se inicia el servicio
       ```bash
       sudo systemctl daemon-reload
       sudo systemctl enable saludo.service
       sudo systemctl start saludo.service
       ```
---
## Logs

Para verificar los logs del servicio:

```bash
sudo journalctl -u saludo.service -f
```

Y para verificar el estado del servicio:
```bash
sudo systemctl status saludo.service
```

