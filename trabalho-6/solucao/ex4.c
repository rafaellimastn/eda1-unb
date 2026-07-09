#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoEquipamento {
    int codigo;
    char nome[100];
    NoEquipamento *esq;
    NoEquipamento *dir;
} NoEquipamento;

char *buscar_equipamento(NoEquipamento *raiz, int codigo) {
    if(raiz == NULL) {
        return "Nao encontrado";
    }

    if(codigo == raiz->codigo) {
        return raiz->nome;
    }

    if(codigo < raiz->codigo) {
        buscar_equipamento(raiz->esq, codigo);
    } else if (codigo > raiz->codigo) {
        buscar_equipamento(raiz->dir, codigo);
    }
}

int main() {

}