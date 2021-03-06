/**
 *
 * Escreva um programa que leia uma string do teclado e converta todos os seus
 * caracteres em mai�scula. Dica: subtraia 32 dos caracteres cujo c�digo ASCII est�
 * entre 97 e 122.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i;
    char nome[MAX];
    char aux[MAX];

    printf("\n Escreva uma string com at� %d caracteres:\n > ", MAX);
    gets(nome);

    strcpy(aux, nome);

    // Escrevendo todos os caracteres em mai�sculo
    for (i=0; i<strlen(aux); i++) {
        if (aux[i]>=97 && aux[i]<=122) {
            aux[i]-=32;
        }
    }
    printf("\n A mesma string com todos os caracteres mai�sculos:\n >   %s", aux);

    // Escrevendo todos os caracteres em min�sculo
    for (i=0; i<strlen(aux); i++) {
        if (aux[i]>=65 && aux[i]<=90) {
            aux[i]+=32;
        }
    }
    printf("\n\n A mesma string com todos os caracteres min�sculos:\n >   %s", aux);

    printf("\n\n");
    return 0;
}
