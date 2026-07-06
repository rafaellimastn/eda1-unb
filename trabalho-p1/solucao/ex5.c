#include <stdio.h>

int fatorial(int n) {
    if (n <=1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

int soma_vetor(int v[], int tam) {
    if (tam <= 0) {
        return 0;
    }
    return v[tam - 1] + soma_vetor(v, tam - 1);
}
int main() {

}