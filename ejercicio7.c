#include <stdio.h>
#include <omp.h>

// Función de cálculo 1: Simulando un cálculo pesado
void calculo1() {
    long long sum = 0;
    for (long long i = 0; i < 100000000; i++) {
        sum += i;  // Realiza una operación simple para simular trabajo
    }
    printf("Cálculo 1 realizado\n");
}

// Función de cálculo 2: Simulando un cálculo pesado
void calculo2() {
    long long sum = 0;
    for (long long i = 0; i < 100000000; i++) {
        sum += i;  // Realiza una operación simple para simular trabajo
    }
    printf("Cálculo 2 realizado\n");
}

// Función de cálculo 3: Simulando un cálculo pesado
void calculo3() {
    long long sum = 0;
    for (long long i = 0; i < 100000000; i++) {
        sum += i;  // Realiza una operación simple para simular trabajo
    }
    printf("Cálculo 3 realizado\n");
}

int main() {
    // Establecer el número de hilos que se usarán
    omp_set_num_threads(3);

    // Ejecutar la región paralela
    #pragma omp parallel
    {
        // Secciones paralelas
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Hilo %d: Ejecutando calculo1()\n", omp_get_thread_num());
                calculo1();  // Ejecuta en paralelo en un hilo
            }

            #pragma omp section
            {
                printf("Hilo %d: Ejecutando calculo2()\n", omp_get_thread_num());
                calculo2();  // Ejecuta en paralelo en otro hilo
            }

            #pragma omp section
            {
                printf("Hilo %d: Ejecutando calculo3()\n", omp_get_thread_num());
                calculo3();  // Ejecuta en paralelo en otro hilo
            }
        }
    }

    // Imprimir cuando todas las secciones hayan terminado
    printf("Terminado\n");

    return 0;
}
