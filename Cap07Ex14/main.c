/**
 *
 * O c�digo de C�sar � uma das t�cnicas de criptografia mais simples e conhecidas.
 * � um tipo de substitui��o no qual cada letra do texto � substitu�da por outra,
 * que se apresenta n posi��es ap�s ela no alfabeto. Por exemplo, com uma troca de
 * tr�s posi��es, a letra A seria substitu�da por D, B se tornaria E e assim por diante.
 * Escreva um programa que fa�a uso desse c�digo de C�sar para tr�s posi��es. Entre
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

    printf("\n Escreva uma string com at� %d caracteres:\n > ", MAX);
    gets(nome);

    printf("\n Informe o tamanho do salto: \n");
    scanf("%d", &pos);

    // Aplicando o C�digo Ceasar
    for (i=0; i<strlen(nome); i++) {
        if (nome[i] != 32) {
            nome[i] += pos;
        }
    }

    printf("\n Texto codificado: \n > %s", nome);

    printf("\n\n");
    return 0;
}
