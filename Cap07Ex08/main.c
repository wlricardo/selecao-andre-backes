/**
 *
 * Construa um programa que leia duas strings do teclado. Imprima uma mensagem
 * informando se a segunda string lida está contida dentro da primeira.
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

    char nome[MAX];
    char srcStr[MAX];
    char aux[MAX];
    int i, j;
    int cont = 0;
    int qtde = 0;

    printf("\n Escreva uma string com até %d caracteres:\n > ", MAX);
    gets(nome);

    printf("\n Escreva uma string a ser pesquisada:\n > ");
    gets(srcStr);

    j=0;
    for (i=0; i<strlen(nome); i++) {
        if (nome[i] == srcStr[j]) {
            aux[j] = nome[i];
            j++;
            if (j == strlen(srcStr)-1) {
                if (strcmp(aux, srcStr)) {
                    cont++;
                }
                j=0;
            }
        }
    }

    printf("\n A palavra '%s' aparece %d vezes na palavra '%s'.\n", srcStr, cont, nome);

    printf("\n\n");
    return 0;
}
