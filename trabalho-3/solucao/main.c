#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "types.h"

void print_medida(TMedidas *medida) {
    printf("nome da cidade: %s\n", medida->cidade);
    printf("temperatura registrada: %f\n", medida->temperatura);
}
void print_temperaturas(TTemperaturas *temp) {
    for(int i = 0; i < temp->qtd_medidas; i++) {
        printf("Medida: %d\n", i+1);
        print_medida(&temp->medidas[i]);
    }
}
int print_menu() {
    printf("--MENU--\n");
    printf("(1) Reset\n");
    printf("(2) Inserir\n");
    printf("(3) Estatistica\n");
    printf("(4) Sair\n");

    int index = 0;
    scanf("%d", &index);
    while (getchar() != '\n' && getchar() != EOF);

    return index;
}
TTemperaturas* reset();
TTemperaturas* inserir_medida(TTemperaturas *temp);
void estatistica(TTemperaturas *temp);
void sair(TTemperaturas *temp);

int print_menu();

int main() {
    while (true) {
        TTemperaturas *temp = (TTemperaturas *) malloc(sizeof(TTemperaturas));
        int opcao = print_menu();
        if (opcao == 1) {
            temp = reset();
        } else if (opcao == 2) {
            temp = inserir_medida(temp);
        } else if (opcao == 3) {
            estatistica(temp);
        } else if (opcao == 4) {
            sair(temp);
        }
    }
}

void estatistica(TTemperaturas *temp) {
    float total = 0;
    int maior_temp = 0;
    int menor_temp = 0;
    for (int i = 0; i < temp->qtd_medidas; i++) {
        total += temp->medidas[i].temperatura;
        if (temp->medidas[i].temperatura > temp->medidas[maior_temp].temperatura) {
            maior_temp = i;
        } else if (temp->medidas[i].temperatura < temp->medidas[maior_temp].temperatura) {
            menor_temp = i;
        }
    }
    float media = total / temp->qtd_medidas;
    printf("Media das temperaturas: %f\n", media);
    printf("Maior da temperatura foi da cidade %s: %f graus Celsius.\n", temp->medidas[maior_temp].cidade, temp->medidas[maior_temp].temperatura);
    printf("Menor das temperatura foi da cidade %s: %f graus Celsius.\n", temp->medidas[menor_temp].cidade, temp->medidas[menor_temp].temperatura);
}

TTemperaturas* inserir_medida(TTemperaturas *temp) {
    if (temp->qtd_dias < temp->qtd_medidas+1) {
        printf("Qtd de dias nao pode ser extrapolado\n");
        return temp;
    }
    int temperatura_cidade = 0;
    printf("Qual a temperatura?\n"); 
    scanf("%d", &temperatura_cidade);
    while (getchar() != '\n' && getchar() != EOF); // Limpa o buffer até o Enter
    temp->medidas[temp->qtd_medidas].temperatura = temperatura_cidade;
    
    char nome_cidade[20];
    printf("Qual a cidade?\n");
    fgets(nome_cidade, 20, stdin);
    nome_cidade[strcspn(nome_cidade, "\n")] = '\0';
    strcpy(temp->medidas[temp->qtd_medidas].cidade, nome_cidade);

    temp->qtd_medidas++; // aumenta em 1 a qtd de medidas
    return temp;
}

TTemperaturas* reset() {
    TTemperaturas *temperaturas = (TTemperaturas *) malloc(2 * sizeof(TTemperaturas));
    int max = 0;
    printf("Qual a qtd max de dias?\n");
    scanf("%d", &max);
    
    temperaturas->qtd_dias= max;
    temperaturas->qtd_medidas = 0;

    temperaturas->medidas = malloc(temperaturas->qtd_dias * sizeof(TMedidas));
    temperaturas->medidas[0].temperatura = 0;
    strcpy(temperaturas->medidas[0].cidade, "");

    return temperaturas;
}

void sair(TTemperaturas *temp) {
    free(temp->medidas);
    printf("Ate logo.\n");
}