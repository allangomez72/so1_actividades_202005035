# Actividad 6

1. **¿Incluyendo el proceso inicial, cuantos procesos son creados por el siguiente programa?**   
Razone su respuestas

![Ejercicio1](/actividad6/img/ejercicio1.png)

- La funcion `fork()` crea un proceso hijo y cada vez que se llama se crea otro nuevo proceso, por que por cada llamada a fork() genera nuevos procesos.
Por lo tanto son tres llamadas a `fork()`, al final se crean 8 procesos, 7 nuevos a partir del padre (Proceso inicial).

2. **Utilizando un sistema Linux, escriba un programa en C que cree un proceso hijo (fork)
   que finalmente se convierta en un proceso zombie. Este proceso zombie debe
   permanecer en el sistema durante al menos 60 segundos.**

### Ejecucion del proceso
![Ejecucion](/actividad6/img/ejecucion.png)


### Ver los procesos
![Ejecucion](/actividad6/img/verproceso.png)

3. **Usando el siguiente código como referencia, completar el programa para que sea
ejecutable y responder las siguientes preguntas:**  

[Coidgo C completo](/actividad6/test/test.c)

**¿Cuántos procesos únicos son creados?**  
A partir del flujo del programa los tres `fork()` se crean `6` procesos únicos.

**¿Cuántos hilos únicos son creados?**  
Los hilos explícitos que se crean al hacer la ejecución son `2`, porque al crear dos hijos por los primeros dos `fork()`, se ejecuta la función `pthread_create()`.

![Salida](/actividad6/img/salidatest.png)

----------
#### Allan Gomez - 202005035