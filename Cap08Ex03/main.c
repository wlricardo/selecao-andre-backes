/**
 *
 * Crie uma estrutura para representar as coordenadas de um ponto no plano (posi-
 * ções X e Y). Em seguida, declare e leia do teclado dois pontos e exiba a distância
 * entre eles.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct {
    float coord_x;
    float coord_y;
} Ponto;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Ponto p1, p2;
    double dist;

    // Definição dos pontos
    printf("\n Coordenadas do Ponto 1:\n");
    printf(" > x : "); scanf("%f", &p1.coord_x);
    printf(" > y : "); scanf("%f", &p1.coord_y);

    printf("\n\n Coordenadas do Ponto 2:\n");
    printf(" > x : "); scanf("%f", &p2.coord_x);
    printf(" > y : "); scanf("%f", &p2.coord_y);

    // Calculando a distância entre os pontos
    dist = pow(p1.coord_x - p2.coord_x, 2);
    dist += pow(p1.coord_y - p2.coord_y, 2);
    dist = sqrt(dist);

    printf("\n A distância entre os dois pontos vale %.2lf u.m.", dist);

    printf("\n\n");
    return 0;
}
