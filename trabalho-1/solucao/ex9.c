#include <stdio.h>

void inverte(int *v, int tam) {
    int *inicio = v;
    int *fim = (v+tam-1);

    int index = 0;
    while(index < tam / 2) {
        int temp = *(inicio+index);
        *(inicio+index) = *(fim-index);
        *(fim-index) = temp;
        index++;
    }
}

int main() {
    int vetor[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    inverte(vetor, 8);
    for(int i = 0; i < 8; i++) {
        printf("%d\n", *(vetor+i));
    }
}