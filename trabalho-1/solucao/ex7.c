#include <stdio.h>

int maior(int *v, int tam) {
    int maior = *v;

    for (int i = 1; i < tam; i++) {
        if (*(v+i) > maior) {
            maior = *(v+i);
        }
    }
    return maior;
}

int main() {
    int v[6] = {67, 10, 30, 535, 10, 837};
    
    printf("Maior elemento: %d\n", maior(v, 6));
    return 0;
}