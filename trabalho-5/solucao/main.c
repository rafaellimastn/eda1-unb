#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

// Função para imprimir a árvore deitada (corrigida)
void imprimirArvore(No* raiz, int espaco) {
    if (raiz == NULL) {
        return;
    }

    int dist = 5;
    espaco += dist;

    // Processa a subárvore direita
    imprimirArvore(raiz->dir, espaco);

    // Sem o \n solto aqui, a árvore fica compacta!
    for (int i = dist; i < espaco; i++) {
        printf(" ");
    }
    // Adicionando um indicador visual para o nó
    printf("-> %d\n", raiz->valor);

    // Processa a subárvore esquerda
    imprimirArvore(raiz->esq, espaco);
}

int main() {
    No* raiz = criarNo(15);
    
    raiz->esq = criarNo(8);
    raiz->dir = criarNo(22);
    
    raiz->esq->esq = criarNo(4);
    raiz->esq->dir = criarNo(11);
    
    raiz->dir->esq = criarNo(18);
    raiz->dir->dir = criarNo(27);
    
    raiz->esq->esq->esq = criarNo(2);
    raiz->esq->esq->dir = criarNo(6);
    
    raiz->esq->dir->esq = criarNo(10);
    raiz->esq->dir->dir = criarNo(13);

    printf("\nVisualizacao da Arvore:\n");
    imprimirArvore(raiz, 0);
    printf("\n");

    return 0;
}