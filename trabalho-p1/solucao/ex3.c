#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float preco;
    int qtd;
} Produto;

int main(){
    // Código da questao 2 
    Produto p1;
    strcpy(p1.nome, "Arroz");
    p1.preco = 29.99;
    p1.qtd = 10;

    Produto *ptr = &p1;
    printf("%s\n", ptr->nome);
    printf("%f\n", ptr->preco);
    printf("%d\n", ptr->qtd);
    return 0;
}