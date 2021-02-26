/**
 *
 * Leia uma matriz de tamanho 10 × 3 com as notas de 10 alunos em três provas. Em
 * seguida, calcule e escreva na tela o número de alunos cuja pior nota foi na prova 1,
 * o número de alunos cuja pior nota foi na prova 2 e o número de alunos cuja pior
 * nota foi na prova 3.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

#define ALUNO 10
#define NOTA 3

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    int menor;
    int indice;
    int menor_nota[NOTA];
    int boletim[ALUNO][NOTA];

    // Definindo os elementos de menor_nota[NOTA] como nulos
    for (i=0; i<NOTA; i++) {
        menor_nota[i] = 0;
    }

    // Criar a matriz de notas dos alunos
    printf("\n Notas: \n\n");
    for (i=0; i<ALUNO; i++) {
        printf("\n ALUNO %2d: ",i+1);
        for (j=0; j<NOTA; j++) {
            boletim[i][j] = 4 + (rand() % 6);
            printf("%2d ", boletim[i][j]);
        }
    }
    printf("\n");

    // Verificando onde ocorreu a pior nota
    for (i=0; i<ALUNO; i++) {
        menor = boletim[i][0];
        indice=0;
        for (j=1; j<NOTA; j++) {
            if (boletim[i][j] <= menor) {
                menor = boletim[i][j];
                indice = j;
            }
        }
        menor_nota[indice]++;
    }

    // Escrevendo os resultados:
    for (i=0; i<NOTA; i++) {
        printf("\n Número de alunos onde a %da Nota foi a mais baixa: %d", i+1, menor_nota[i]);
    }

    printf("\n\n");
    return 0;
}
