#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        printf("Thread %d reached the barrier\n", omp_get_thread_num());

        // Sincroniza todos los hilos en este punto
        #pragma omp barrier

        // Después de la barrera, todos los hilos continúan
        printf("Thread %d passed the barrier\n", omp_get_thread_num());
    }

    return 0;
}
