#include <stdio.h>
#include <stdlib.h>

// Definimos uma estrutura para organizar os dados dos produtos
typedef struct {
    char nome[50];
    float preco;
    int qtd;
} Produto;

int main() {
    FILE *write_file = fopen("produtos.txt", "w");
    
    if (write_file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }
    
    Produto p1 = {"Teclado", 149.90, 5};
    Produto p2 = {"Mouse", 129.50, 10};
    
    fprintf(write_file, "%s\n%.2f\n%d\n", p1.nome, p1.preco, p1.qtd);
    fprintf(write_file, "%s\n%.2f\n%d\n", p2.nome, p2.preco, p2.qtd);
    
    fclose(write_file);
    printf("Arquivo 'produtos.txt' gravado e fechado com sucesso.\n\n");
    
    FILE * read_file = fopen("produtos.txt", "r");
    
    if (read_file == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }
    
    Produto produto;
    int contador = 1;
    
    printf("=== DADOS LIDOS DO ARQUIVO ===\n");
    while (fscanf(read_file, " %s %f %d", produto.nome, &produto.preco, &produto.qtd) == 3) {
        printf("Produto %d:\n", contador++);
        printf("Nome: %s\n", produto.nome);
        printf("Preco: R$ %.2f\n", produto.preco);
        printf("Quantidade: %d\n", produto.qtd);
    }
    
    fclose(read_file);
    
    return 0;
}