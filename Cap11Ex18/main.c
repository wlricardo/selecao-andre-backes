/**
 *
 * Escreva uma fun��o que receba como par�metro duas matrizes, A e B, e seus
 * tamanhos. A fun��o deve retornar o ponteiro para uma matriz C, em que C � o
 * produto da multiplica��o da matriz A pela matriz B. Se a multiplica��o das
 * matrizes n�o for poss�vel, retorne um ponteiro nulo.
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

// Fun��o produto de matrizes quadradas
int **produto_matriz_quadrada(int **m, int **n, int lin_m, int col_m, int lin_n, int col_n) {

    int **produto;
    int soma;
    int i, j, k;

    if (col_m != lin_n) {
        return NULL;
    } else {
        produto = (int**)malloc(lin_m*sizeof(int*));
        for (i=0; i<lin_m; i++) {
            produto[i] = (int*)malloc(col_n*sizeof(int));
            for (j=0; j<col_n; j++) {
                soma=0;
                for (k=0; k<lin_n; k++) {
                    soma += (m[i][k] * n[k][j]);
                    produto[i][j] = soma;
                }
            }
        }
    }
    return produto;
}

// Fun��o para desalocar a matriz
void libera_matriz(int **m, int n){
    int i;
    for(i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int dim;
    int lin_A, col_A;
    int lin_B, col_B;
    int i, j;
    int **mat_A;
    int **mat_B;
    int **produto;

    // Fornecendo as dimens�es da matriz:
    printf("\n N�mero de linhas da Matriz A: "); scanf("%d", &lin_A);
    fflush(stdin);
    printf(" N�mero de colunas da Matriz A: "); scanf("%d", &col_A);
    fflush(stdin);
    printf("\n N�mero de linhas da Matriz B: "); scanf("%d", &lin_B);
    fflush(stdin);
    printf(" N�mero de colunas da Matriz B: "); scanf("%d", &col_B);
    fflush(stdin);

    system("cls");
    // Gerando as matrizes quadradas de inteiros de forma aleat�ria
    printf("\n Matriz A:\n\n");
    mat_A = matriz_de_inteiros(lin_A, col_A);
    for (i=0; i<lin_A; i++) {
        for (j=0; j<col_A; j++) {
            printf(" %2d", mat_A[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n Matriz B:\n\n");
    mat_B = matriz_de_inteiros(lin_B, col_B);
    for (i=0; i<lin_B; i++) {
        for (j=0; j<col_B; j++) {
            printf(" %2d", mat_B[i][j]);
        }
        printf("\n");
    }

    // Verifica se o produto � vi�vel e o calcula, caso positivo
    produto = produto_matriz_quadrada(mat_A, mat_B, lin_A, col_A, lin_B, col_B);
    if (produto==NULL) {
        printf("\n\n As dimens�es das matrizes n�o s�o compat�veis para realizar o produto.\n\n");
    } else {
        // Imprimindo a matriz de inteiros gerada automaticamente
        printf("\n\n\n Produto:\n\n");
        for (i=0; i<lin_A; i++) {
            for (j=0; j<col_B; j++) {
                printf(" %3d", produto[i][j]);
            }
            printf("\n");
        }
    }

    libera_matriz(mat_A, col_A);
    libera_matriz(mat_B, col_B);
    libera_matriz(produto, col_B);
    printf("\n\n");
    return 0;
}
