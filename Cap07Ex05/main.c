/**
 *
 * Faça um programa que leia uma string e a inverta. A string invertida deve ser
 * armazenada na mesma variável. Em seguida, imprima a string invertida.
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
    char aux;
    int i, n;

    printf("\n Escreva uma palavra de até %d caracteres:\n > ", MAX);
    gets(nome); fflush(stdin);
    n=strlen(nome);

    printf("\n Palavra escrita de trás para frente: ");
    for (i=0; i < n/2; i++) {
        aux=nome[i];
        nome[i]=nome[n-1-i];
        nome[n-1-i]=aux;
    }
    printf("%s", nome);

    printf("\n\n");
    return 0;
}
