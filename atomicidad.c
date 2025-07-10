#include <stdio.h>
#include <omp.h>

int counter = 0;

int main() {
    #pragma omp parallel num_threads(4)
    {
        // Operación atómica para incrementar 'counter'
        #pragma omp atomic
        counter++;  // Incremento de la variable compartida de forma atómica
    }

    printf("Final counter value: %d\n", counter);
    return 0;
}
