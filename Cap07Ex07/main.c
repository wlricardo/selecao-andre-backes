/**
 *
 * Fa�a um programa que leia uma string e imprima uma mensagem dizendo se ela
 * � um pal�ndromo ou n�o. Um pal�ndromo � uma palavra que tem a propriedade
 * de poder ser lida tanto da direita para a esquerda como da esquerda para a direita.
 * Exemplos: ovo, arara, rever, asa, osso etc.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 30

int is_palindrome(char *str, int n) {
    char strAux[n];
    char aux;
    int i;

    // Cria uma c�pia de str em strAux;
    strcpy(strAux, str);

    // Escreve strAux ao contr�rio
    for (i=0; i < n/2; i++) {
        aux=strAux[i];
        strAux[i]=strAux[n-1-i];
        strAux[n-1-i]=aux;
    }

    // Verifica se � pal�ndrome
   return (!strcmp(strAux, str));
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char nome[MAX];
    int i, n;

    printf("\n Escreva uma palavra de at� %d caracteres:\n > ", MAX);
    gets(nome); fflush(stdin);
    n=strlen(nome);

    if (is_palindrome(nome, strlen(nome))) {
        printf("\n A palavra '%s' � pal�ndrome.\n", nome);
    } else {
        printf("\n A palavra '%s' n�o � pal�ndrome.\n", nome);
    }

    printf("\n\n");
    return 0;
}
