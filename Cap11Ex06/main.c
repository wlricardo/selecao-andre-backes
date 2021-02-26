/**
 *
 * Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimens�es
 * da matriz dever�o ser lidas do usu�rio. Em seguida, escreva uma fun��o
 * que receba um valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no
 * caso contr�rio.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Fun��o para gerar uma matriz bidimensional de inteiros aleat�rios
int **matriz_de_inteiros(int lin, int col) {

    int **mat;
    int i, j;

    mat = (int**)malloc(lin*sizeof(int*));
    if (mat==NULL) {
        printf("\n\n Erro de aloca��o de mem�ria !!\n\n");
    }
    for (i=0; i<lin; i++) {
        mat[i] = (int*)malloc(col*sizeof(int));
        if (mat[i]==NULL) {
            printf("\n\n Erro de aloca��o de mem�ria !!\n\n");
        }
        for (j=0; j<col; j++) {
            mat[i][j] = 1 + (rand()%20);
        }
    }
    return mat;
}

// Fun��o para desalocar a matriz
void libera_matriz(int **m, int n){
    int i;
    for(i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

// Fun��o para verificar se um dado inteiro est� na matriz
int esta_na_matriz(int **mat, int lin, int col, int valor) {

    int i, j;
    for (i=0; i<lin; i++) {
        for (j=0; j<col; j++) {
            if (mat[i][j] == valor) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int lin, col;
    int valor;
    int i, j;
    int **m;

    // Fornecendo as dimens�es da matriz:
    printf("\n N�mero de linhas: "); scanf("%d", &lin);
    fflush(stdin);
    printf(" N�mero de colunas: "); scanf("%d", &col);
    fflush(stdin);

    // Imprimindo a matriz de inteiros gerada automaticamente
    printf("\n Matriz:\n\n");
    m = matriz_de_inteiros(lin,col);
    for (i=0; i<lin; i++) {
        for (j=0; j<col; j++) {
            printf(" %2d", m[i][j]);
        }
        printf("\n");
    }

    printf("\n\n Insira o valor que deseja procurar: ");
    scanf("%d", &valor); fflush(stdin);

    if (esta_na_matriz(m, lin, col, valor)) {
        printf("\n O valor %d est� na matriz.\n", valor);
    } else {
        printf("\n O valor %d n�o est� na matriz.\n", valor);
    }

    libera_matriz(m, lin);
    printf("\n\n");
    return 0;
}
