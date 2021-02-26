/**
 *
 * Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimensões
 * da matriz deverão ser lidas do usuário. Em seguida, escreva uma função
 * que receba um valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no
 * caso contrário.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Função para gerar uma matriz bidimensional de inteiros aleatórios
int **matriz_de_inteiros(int lin, int col) {

    int **mat;
    int i, j;

    mat = (int**)malloc(lin*sizeof(int*));
    if (mat==NULL) {
        printf("\n\n Erro de alocação de memória !!\n\n");
    }
    for (i=0; i<lin; i++) {
        mat[i] = (int*)malloc(col*sizeof(int));
        if (mat[i]==NULL) {
            printf("\n\n Erro de alocação de memória !!\n\n");
        }
        for (j=0; j<col; j++) {
            mat[i][j] = 1 + (rand()%20);
        }
    }
    return mat;
}

// Função para desalocar a matriz
void libera_matriz(int **m, int n){
    int i;
    for(i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

// Função para verificar se um dado inteiro está na matriz
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

    // Fornecendo as dimensões da matriz:
    printf("\n Número de linhas: "); scanf("%d", &lin);
    fflush(stdin);
    printf(" Número de colunas: "); scanf("%d", &col);
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
        printf("\n O valor %d está na matriz.\n", valor);
    } else {
        printf("\n O valor %d não está na matriz.\n", valor);
    }

    libera_matriz(m, lin);
    printf("\n\n");
    return 0;
}
