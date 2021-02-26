/**
 *
 * Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela possui. Entre
 * com um caractere (vogal ou consoante) e substitua todas as vogais da palavra dada
 * por esse caractere. Ao final, imprima a nova string e o número de vogais que ela
 * possui.
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
    char vogal;
    char vogais[12] = "AEIOUaeiou";
    int num_vogais = 0;
    int i, j;

    printf("\n Escreva uma palavra de até %d caracteres:\n > ", MAX);
    gets(nome); fflush(stdin);

    // Contando o número de vogais da palavra fornecida.
    for (i=0; i<strlen(nome); i++) {
        for (j=0; j<strlen(vogais); j++) {
            if (nome[i]==vogais[j]) {
                num_vogais++;
            }
        }
    }
    // Substituindo as vogais por um caractere fornecido pelo usuário
    printf("\n Forneça um caractere para substituir as vogais: ");
    vogal=getchar();
    printf("\n A palavra '%s' possui %d vogais.", nome, num_vogais);
    for (i=0; i<strlen(nome); i++) {
        for (j=0; j<strlen(vogais); j++) {
            if (nome[i]==vogais[j]) {
                nome[i] = vogal;
            }
        }
    }
    printf("\n A palavra após as substituições: %s", nome);

    printf("\n\n");
    return 0;
}
