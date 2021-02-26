/**
 *
 * Faça um programa que leia uma string e imprima uma mensagem dizendo se ela
 * é um palíndromo ou não. Um palíndromo é uma palavra que tem a propriedade
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

    // Cria uma cópia de str em strAux;
    strcpy(strAux, str);

    // Escreve strAux ao contrário
    for (i=0; i < n/2; i++) {
        aux=strAux[i];
        strAux[i]=strAux[n-1-i];
        strAux[n-1-i]=aux;
    }

    // Verifica se é palíndrome
   return (!strcmp(strAux, str));
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char nome[MAX];
    int i, n;

    printf("\n Escreva uma palavra de até %d caracteres:\n > ", MAX);
    gets(nome); fflush(stdin);
    n=strlen(nome);

    if (is_palindrome(nome, strlen(nome))) {
        printf("\n A palavra '%s' é palíndrome.\n", nome);
    } else {
        printf("\n A palavra '%s' não é palíndrome.\n", nome);
    }

    printf("\n\n");
    return 0;
}
