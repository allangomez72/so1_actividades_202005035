#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Crear el proceso hijo
    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        printf("Proceso hijo (PID: %d) terminado.\n", getpid());
        exit(0); // El hijo termina inmediatamente
    } else {
        // Proceso padre
        printf("Proceso padre (PID: %d) creó al hijo (PID: %d).\n", getpid(), pid);

        // Esperar 60 segundos antes de llamar a wait(), lo que mantiene al proceso hijo como zombie
        sleep(60);

        // Recolectar el estado del proceso hijo para evitar el proceso zombie
        wait(NULL);

        printf("Proceso hijo recolectado (PID: %d).\n", pid);
    }

    return 0;
}
