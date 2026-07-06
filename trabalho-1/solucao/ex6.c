#include <stdio.h>

void dobra(int *x) {
    (*x) *= 2;
}
int main() {
    int x = 8;
    int *ptr = &x;
    dobra(ptr);
    printf("x: %d\n", x);
    
    return 0;
}