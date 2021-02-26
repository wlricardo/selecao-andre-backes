/**
 *
 * Elabore uma função que receba três notas de um aluno como parâmetros e uma
 * letra. Se a letra for “A”, a função deverá calcular a média aritmética das notas do
 * aluno; se for “P”, deverá calcular a média ponderada, com pesos 5, 3 e 2. Retorne
 * a média calculada para o programa principal.
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

    printf("\n\n Informe o tipo de média desejada: ");
    op = getchar(); fflush(stdin);
    op = toupper(op);

    while ((op != 'A') && (op != 'P')) {
        printf(" Operaçao inválida. Tente novamente !! ");
        printf("\n\n Informe o tipo de média desejada: ");
        op = getchar(); fflush(stdin);
        op = toupper(op);
    }

    media = calcular_media(notas, MAX, op);
    printf("\n\n Média: %.2f", media);

    printf("\n\n");
    return 0;
}
