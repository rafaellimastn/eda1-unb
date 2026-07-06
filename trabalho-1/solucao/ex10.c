#include <stdio.h>

void intercala(int *v1, int *v2, int *v3, int n) {
    for(int i = 0; i < 2*n; i++) {
        if ((i % 2) == 0) {
            *(v3+i) = *(v1+(i/2));
        } else {
            *(v3+i) = *(v2+(i/2));
        }
    }
}

int main() {
    int v1[3] = {1, 3, 5};
    int v2[3] = {2, 4, 6};
    int v3[6] = {0};
    intercala(v1, v2, v3, 3);

    for(int i = 0; i < 6; i++) {
        printf("%d\n", *(v3+i));
    }
}