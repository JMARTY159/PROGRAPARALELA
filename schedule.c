#include <stdio.h>
#include <omp.h>

// Simula una operación de cálculo costoso
void calculo() {
    long long sum = 0;
    for (long long i = 0; i < 1000000; i++) {
        sum += i;  // Realiza una operación simple para simular un cálculo costoso
    }
}

int main() {
    // Establecer el número de hilos a 3 (uno por cada sección)
    omp_set_num_threads(3);

    // Ejecutar la región paralela con secciones
    #pragma omp parallel
    {
        #pragma omp sections
        {
            // Asigna tareas a diferentes hilos (secciones paralelas)
            #pragma omp section
            {
                printf("Hilo %d ejecutando calculo1()\n", omp_get_thread_num());
                calculo();
            }

            #pragma omp section
            {
                printf("Hilo %d ejecutando calculo2()\n", omp_get_thread_num());
                calculo();
            }

            #pragma omp section
            {
                printf("Hilo %d ejecutando calculo3()\n", omp_get_thread_num());
                calculo();
            }
        }
    }

    // Imprimir cuando todas las secciones hayan terminado
    printf("Terminado\n");

    return 0;
}
