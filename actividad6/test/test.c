#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void* hilo_funcion(void *arg) {
    printf("Hilo: Se ha creado un hilo en el proceso con PID: %d, ID del hilo: %lu\n", getpid(), pthread_self());
}

int main() {
    pid_t pid;
    pthread_t hilo_id;

    printf("Proceso principal con PID: %d\n", getpid());

    pid = fork();
    if (pid == 0) { // Primer proceso hijo
        printf("Nuevo proceso hijo con PID: %d, proceso padre PID: %d\n", getpid(), getppid());

        pid_t pid_hijo = fork();
        if (pid_hijo == 0) { // Proceso nieto
            printf("Proceso nieto con PID: %d, su padre es PID: %d\n", getpid(), getppid());
        }

        // Creación de hilo tanto en el hijo como en el nieto
        pthread_create(&hilo_id, NULL, hilo_funcion, NULL);
    } else {
        wait(NULL); //para los procesos
    }

    // Creación de un nuevo proceso hijo desde cualquier proceso que llegue a este punto
    pid = fork();
    if (pid == 0) { // Segundo proceso hijo
        printf("Segundo hijo creado, PID: %d, su padre es PID: %d\n", getpid(), getppid());
    } else {
        wait(NULL);//para el proceso
    }

    return 0;
}
