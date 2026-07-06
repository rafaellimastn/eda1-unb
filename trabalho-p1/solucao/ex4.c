#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float preco;
    int qtd;
} Produto;

int main(){
    int n = 0;
    printf("Qual o tamanho do seu array?\n");
    scanf("%d", &n);    
    getchar();

    Produto *arr = (Produto *) malloc(n * sizeof(Produto));

    for (int i = 0; i < n; i++) {
        printf("Qual o nome do item (%d/%d)?\n", (i+1), n);
        fgets((arr+i)->nome, 50, stdin);
        (arr+i)->nome[strcspn((arr+i)->nome, "\n")] = '\0';

        printf("Qual o preco do item (%d/%d)?\n", (i+1), n);
        scanf("%f", &(arr+i)->preco);

        printf("Qual a quantidade do item (%d/%d)?\n", (i+1), n);
        scanf("%d", &(arr+i)->qtd);
        getchar();
    }

    printf("\n=== PRODUTOS CADASTRADOS ===\n");
    for (int i = 0; i < n; i++) {
        printf("Produto %d: %s | ", (i+1), (arr+i)->nome);
        printf("Preco: %.2f | Quantidade: %d\n", (arr+i)->preco, (arr+i)->qtd);
    }

    free(arr);
    return 0;
}