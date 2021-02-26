/**
 *
 * Elabore uma fun��o que receba tr�s notas de um aluno como par�metros e uma
 * letra. Se a letra for �A�, a fun��o dever� calcular a m�dia aritm�tica das notas do
 * aluno; se for �P�, dever� calcular a m�dia ponderada, com pesos 5, 3 e 2. Retorne
 * a m�dia calculada para o programa principal.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX 3

float calcular_media(float *notas, int dim, char op) {
    int i;
    int pesos[3] = {5, 3, 2};
    float media=0.0;


    if (toupper(op) == 'A') {
        for (i=0; i<dim; i++) {
            media += notas[i];
        }
        media /= (1.0*dim);
    }
    if (toupper(op == 'P')) {
        for (i=0; i<dim; i++) {
            media += (notas[i] * pesos[i]);
        }
        media /= 10.0;
    }
    return media;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int i;
    char op;
    float media;
    float notas[MAX];

    printf("\n\n Notas: \n");
    for (i=0; i<MAX; i++) {
        notas[i] = 5.0 + (rand()%5);
        printf(" %.2f", notas[i]);
    }

    printf("\n\n Informe o tipo de m�dia desejada: ");
    op = getchar(); fflush(stdin);
    op = toupper(op);

    while ((op != 'A') && (op != 'P')) {
        printf(" Opera�ao inv�lida. Tente novamente !! ");
        printf("\n\n Informe o tipo de m�dia desejada: ");
        op = getchar(); fflush(stdin);
        op = toupper(op);
    }

    media = calcular_media(notas, MAX, op);
    printf("\n\n M�dia: %.2f", media);

    printf("\n\n");
    return 0;
}
