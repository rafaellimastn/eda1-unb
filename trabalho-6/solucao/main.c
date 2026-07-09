#include <stdio.h>
#include <stdlib.h>

typedef struct TNoBin{
    int chave;
    struct TNoBin *esq;
    struct TNoBin *dir;
} TNoBin;

TNoBin* criar_no(int chave) {
    TNoBin *novo_no = (TNoBin *) malloc(sizeof(TNoBin));
    if (novo_no != NULL) {
        novo_no->chave = chave;
        novo_no->dir = NULL;
        novo_no->esq = NULL;
    }
    return novo_no;
}

TNoBin* inserir_no(TNoBin *raiz, int chave) {
    if (raiz == NULL) {
        return criar_no(chave);
    }
    if(chave < raiz->chave) {
        raiz->esq = inserir_no(raiz->esq,chave);
    } else if (chave > raiz->chave) {
        raiz->dir = inserir_no(raiz->dir, chave);
    }
    return raiz;
}

TNoBin* buscar_no(TNoBin *raiz, int chave) {
    if(raiz == NULL || chave == raiz->chave) {
        return raiz;
    }
    if(chave < raiz->chave) {
        return buscar_no(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        return buscar_no(raiz->dir, chave);
    }
}

void imprimirArvore(TNoBin* raiz, int espaco) {
    if (raiz == NULL) {
        return;
    }

    int dist = 5;
    espaco += dist;

    imprimirArvore(raiz->dir, espaco);

    for (int i = dist; i < espaco; i++) {
        printf(" ");
    }
    printf("-> %d\n", raiz->chave);

    imprimirArvore(raiz->esq, espaco);
}

int main() {
    TNoBin *raiz = NULL;
    raiz = inserir_no(raiz, 30);

    inserir_no(raiz, 10);
    inserir_no(raiz, 40);
    inserir_no(raiz, 20);
    inserir_no(raiz, 5);
    inserir_no(raiz, 50);
    inserir_no(raiz, 30);

    imprimirArvore(raiz, 0);
}