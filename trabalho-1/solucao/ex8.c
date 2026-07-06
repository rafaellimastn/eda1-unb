#include <stdio.h>

int conta(char *s, char c) {
    int contador = 0, index = 0;
    while (*(s+index) != '\0')
    {
        if (*(s+index) == c) {
            contador++;
        }
        index++;
    }
    return contador;
}

int main() {
    char nome[] = "programacao";
    printf("O caractere '%c' aparece: %d vezes\n", 'a', conta(nome, 'a'));
    return 0;
}