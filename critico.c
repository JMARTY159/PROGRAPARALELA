#include <stdio.h>
#include <omp.h>

int counter = 0;

int main() {
    #pragma omp parallel num_threads(4)
    {
        // Solo un hilo a la vez puede ejecutar esta sección crítica
        #pragma omp critical
        {
            counter++;  // Acceso y modificación de la variable compartida
            printf("Thread %d incremented counter to %d\n", omp_get_thread_num(), counter);
        }
    }

    printf("Final counter value: %d\n", counter);
    return 0;
}
