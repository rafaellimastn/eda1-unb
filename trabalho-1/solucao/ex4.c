// Swap manual

int main() {
    int A = 10, B = 20;
    int *p1, *p2;
    p1 = &A;
    p2 = &B;

    printf("A: %d\n", *p1);
    printf("B: %d\n", *p2);

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("A: %d\n", *p1);
    printf("B: %d\n", *p2);

    return 0;
}