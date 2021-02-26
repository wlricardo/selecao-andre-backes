/**
 *
 * O código de César é uma das técnicas de criptografia mais simples e conhecidas.
 * É um tipo de substituição no qual cada letra do texto é substituída por outra,
 * que se apresenta n posições após ela no alfabeto. Por exemplo, com uma troca de
 * três posições, a letra A seria substituída por D, B se tornaria E e assim por diante.
 * Escreva um programa que faça uso desse código de César para três posições. Entre
 * com uma string e imprima a string codificada.
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
    int pos;
    int i;

    printf("\n Escreva uma string com até %d caracteres:\n > ", MAX);
    gets(nome);

    printf("\n Informe o tamanho do salto: \n");
    scanf("%d", &pos);

    // Aplicando o Código Ceasar
    for (i=0; i<strlen(nome); i++) {
        if (nome[i] != 32) {
            nome[i] += pos;
        }
    }

    printf("\n Texto codificado: \n > %s", nome);

    printf("\n\n");
    return 0;
}
