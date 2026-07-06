// Incremento indireto
#include <stdio.h>

int main() {
    int var = 5;

    int *ptr = &var;
    printf("num: %d\n", *ptr);

    *ptr += 5;
    printf("(num + 5): %d\n", *ptr);

    *ptr *= 2;
    printf("(num + 5) * 2: %d\n", *ptr);

    return 0;
}