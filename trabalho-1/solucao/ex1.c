// Inspecao de memoria
#include <stdio.h>

int main() {
    int var_int = 10;
    float var_float = 9.5;

    int *ptr_int = &var_int;
    float *ptr_float = &var_float;

    printf("Inteiro: %d\n", *ptr_int);
    printf("Ponto flutuante: %f\n", *ptr_float);

    return 0;
}