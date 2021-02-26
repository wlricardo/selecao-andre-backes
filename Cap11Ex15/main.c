/**
 *
 * Escreva uma fun��o que receba como par�metro uma matriz A contendo N linhas
 * e N colunas, e um vetor B de tamanho N. A fun��o deve retornar o ponteiro para
 * um vetor C de tamanho N alocado dinamicamente, em que C � o produto da
 * matriz A pelo vetor B.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Fun��o para gerar uma matriz bidimensional de inteiros aleat�rios
int **matriz_de_inteiros(int dim) {

    int **mat;
    int i, j;

    mat = (int**)malloc(dim*sizeof(int*));
    if (mat==NULL) {
        printf("\n\n Erro de aloca��o de mem�ria !!\n\n");
    }
    for (i=0; i<dim; i++) {
        mat[i] = (int*)malloc(dim*sizeof(int));
        if (mat[i]==NULL) {
            printf("\n\n Erro de aloca��o de mem�ria !!\n\n");
        }
        for (j=0; j<dim; j++) {
            mat[i][j] = 1 + (rand()%20);
        }
    }
    return mat;
}

// Fun��o produto de matrizes quadradas
int **produto_matriz_quadrada(int **m, int **n, int dim) {

    int **produto;
    int soma;
    int i, j, k;

    produto = (int**)malloc(dim*sizeof(int*));
    for (i=0; i<dim; i++) {
        produto[i] = (int*)malloc(dim*sizeof(int));
        for (j=0; j<dim; j++) {
            soma=0;
            for (k=0; k<dim; k++) {
                soma += (m[i][k] * n[k][j]);
                produto[i][j] = soma;
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
    int i, j;
    int **mat_A;
    int **mat_B;
    int **produto;

    // Fornecendo as dimens�es da matriz:
    printf("\n Dimens�o da matriz quadrada: "); scanf("%d", &dim);
    fflush(stdin);

    // Gerando as matrizes quadradas de inteiros de forma aleat�ria
    printf("\n Matriz A:\n\n");
    mat_A = matriz_de_inteiros(dim);
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) {
            printf(" %2d", mat_A[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n Matriz B:\n\n");
    mat_B = matriz_de_inteiros(dim);
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) {
            printf(" %2d", mat_B[i][j]);
        }
        printf("\n");
    }

    produto = produto_matriz_quadrada(mat_A, mat_B, dim);
    // Imprimindo a matriz de inteiros gerada automaticamente
    printf("\n\n\n Produto:\n\n");
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) {
            printf(" %5d", produto[i][j]);
        }
        printf("\n");
    }


    libera_matriz(mat_A, dim);
    libera_matriz(mat_B, dim);
    libera_matriz(produto, dim);
    printf("\n\n");
    return 0;
}
