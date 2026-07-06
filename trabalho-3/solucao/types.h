#ifndef FOO_H_   /* Include guard */
#define FOO_H_

typedef struct {
    char cidade[20];
    float temperatura;
} TMedidas;

typedef struct {
    int qtd_dias;
    int qtd_medidas;
    TMedidas *medidas;
} TTemperaturas;


#endif
