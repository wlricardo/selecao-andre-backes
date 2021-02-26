/**
 *
 * Leia uma matriz de tamanho N � N. Em seguida, imprima a soma dos valores
 * contidos em sua diagonal secund�ria.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

#define MAX 10

int main()
{
    srand(time(NULL));                  // Seed para gerar n�meros aleat�rios
    setlocale(LC_ALL, "Portuguese");    // Exibir acentos gr�ficos do portugu�s

    int i, j;
    int vet[MAX][MAX];
    int soma = 0;

    // Criando a matriz quadrada de tamanho M
    printf("\n M[%d][%d] = \n\n", MAX, MAX);
    for (i=0; i<MAX; i++) {
        printf(" | ");
        for (j=0; j<MAX; j++) {
            vet[i][j] = rand()%30;
            printf("%2d ", vet[i][j]);
        }
        printf(" |\n");
    }

    j=MAX-1;
    for (i=0; i<MAX; i++) {
        soma += vet[i][j];
        j--;
    }

    printf("\n Soma dos elementos da diagonal secund�ria: %d\n\n", soma);

    return 0;
}
