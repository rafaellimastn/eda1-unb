#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float preco;
    int qtd;
} Produto;

int main() {
    Produto p1;

    strcpy(p1.nome, "Arroz");
    printf("%s\n", p1.nome);

    p1.preco = 29.99;
    printf("%f\n", p1.preco);

    p1.qtd = 10;
    printf("%d\n", p1.qtd);

    return 0;
}