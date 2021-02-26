/**
 *
 * Fa�a um programa que calcule o desvio-padr�o d de um vetor V contendo n n�meros
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define MAX 10

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int i;
    int vet[MAX];
    int soma = 0;
    float media = 0.0;
    float desvio_padrao = 0.0;

    // Cria��o e exibi��o do vetor de inteiros
    printf("\n V = [");
    for (i=0; i<MAX; i++) {
        vet[i] = rand() % 100;
        soma+=vet[i];
        printf("%2d ", vet[i]);
    }
    printf("]\n");

    // C�lculo da m�dia
    media = soma/MAX;

    // C�lculo do desvio-padr�o
    for (i = 0; i<MAX; i++) {
        desvio_padrao += pow(vet[i] - media, 2);
    }
    desvio_padrao = sqrt(desvio_padrao/(MAX-1));

    printf("\n O desvio-padr�o dos valores � %.4f\n", desvio_padrao);

    return 0;
}
