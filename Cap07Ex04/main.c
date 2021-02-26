/**
 *
 * Fa�a um programa que leia uma string e a imprima de tr�s para a frente.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 30

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char nome[MAX];
    int i;

    printf("\n Escreva uma palavra de at� %d caracteres:\n > ", MAX);
    fgets(nome, MAX, stdin); setbuf(stdin, NULL);

    printf("\n Palavra escrita de tr�s para frente: ");
    for (i=strlen(nome)-1; i >= 0; i--) {
        printf("%c", nome[i]);
    }

    printf("\n\n");
    return 0;
}
