#include <stdio.h>

int main() {
    int vetor[10] = {0};
    for (int i = 0; i < 10; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    int m[3][3] = {0};
    for(int i = 0; i < 3; i++) {
        m[i][i] = 1;
    }
    return 0;
}