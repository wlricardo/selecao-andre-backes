/**
 *
 * Crie uma fun��o que receba uma string e retorne o ponteiro para essa string invertida.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 1000

// Fun��o que inverte string
char *inverte_string(char *palavra, int tamanho) {

    char *inverte;
    int i;

    inverte = (char*)malloc(tamanho*sizeof(char));
    if (inverte == NULL) {
        printf("\n\n Erro de aloca��o de mem�ria !\n\n");
    }
    for (i=0; i<tamanho; i++) {
        inverte[i] = palavra[tamanho-i-1];
    }
    return inverte;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char my_string[MAX];
    char *string_invertida;
    int tamanho;

    printf("\n\n Escreve sua string: \n > ");
    gets(my_string); fflush(stdin);

    tamanho = strlen(my_string);

    string_invertida = inverte_string(my_string, tamanho);
    printf("\n String invertida:\n > %s\n\n", string_invertida);

    return 0;
}
