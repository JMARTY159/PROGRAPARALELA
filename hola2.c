#include <stdio.h>
#include <math.h>
#include <omp.h>

void calculo_pesado(double* res) {
    *res = 0.0;
    for (int j = 0; j < 10000; j++) {
        *res += sin(j) * cos(j);  // Operaciones matemáticas pesadas
    }
}

int main() {
    double res[10000];
    double start_time, end_time;

    // Medir el tiempo de ejecución de la versión paralela
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < 10000; i++) {
        calculo_pesado(&res[i]);
    }
    end_time = omp_get_wtime();
    printf("Tiempo de ejecución (paralela): %f segundos\n", end_time - start_time);

    return 0;
}
