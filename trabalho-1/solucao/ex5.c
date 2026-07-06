// Vetor com ponteiros
#include <stdio.h>

int main() {
    int v[5] = {10, 20, 30, 40, 50};
    int *ptr = v;
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: %d\n", (i + 1), *(ptr+i));
    }
    
    return 0;
}