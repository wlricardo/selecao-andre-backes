/**
 *
 * Crie um programa que contenha um array de float contendo 10 elementos. Imprima
 * o endere�o de cada posi��o desse array.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int i;
    float num_reais[10];

    printf("\n Conte�do do array de float: \n");
    for (i=0; i<10; i++) {
        num_reais[i] = (100 + (rand()%1000))*0.01;
        printf("\n num_reais[%d]: %5.2f", i, num_reais[i]);
    }

    printf("\n\n\n\n Imprimindo os endere�os de cada posi��o do array:\n");
    for (i=0; i<10; i++) {
        printf("\n &num_reais[%d]: %p", i, &num_reais[i]);
    }

    printf("\n\n");
    return 0;
}
