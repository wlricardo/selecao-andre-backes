/**
 *
 * Faça um programa que leia uma matriz de tamanho 6 × 6. Calcule e imprima a
 * soma dos elementos dessa matriz que estão abaixo da diagonal principal.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

#define MAX 6

int main()
{
    srand(time(NULL));                  // Seed para gerar números aleatórios
    setlocale(LC_ALL, "Portuguese");    // Exibir acentos gráficos do português

    int i, j;
    int matriz[MAX][MAX];
    int soma = 0;

    // Criando a matriz quadrada de tamanho M
    printf("\n M[%d][%d] = \n\n", MAX, MAX);
    for (i=0; i<MAX; i++) {
        printf(" | ");
        for (j=0; j<MAX; j++) {
            matriz[i][j] = rand()%30;
            printf("%2d ", matriz[i][j]);
            if ((i!=j) && (i+j != MAX-1)) {
                soma+=matriz[i][j];
            }
        }
        printf(" |\n");
    }

    printf("\n Soma dos elementos abaixo da diagonal principal: %d\n\n", soma);

    return 0;
}
