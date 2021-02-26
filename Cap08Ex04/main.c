/**
 *
 * Crie uma estrutura chamada Ret�ngulo. Essa estrutura dever� conter o ponto
 * superior esquerdo e o ponto inferior direito do ret�ngulo. Cada ponto � definido
 * por uma estrutura Ponto, a qual cont�m as posi��es X e Y. Fa�a um programa que
 * declare e leia uma estrutura Ret�ngulo e exiba a �rea e o comprimento da diagonal
 * e o per�metro desse ret�ngulo.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    float coord_x;
    float coord_y;
} Ponto;

typedef struct {
    Ponto supE, infD;
    float area;
    float perimetro;
} Retangulo;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Retangulo ret;
    float base;
    float altura;

    // Defini��o dos pontos
    printf("\n Coordenadas do ponto superior esquerdo:\n");
    printf(" > x : "); scanf("%f", &ret.supE.coord_x);
    printf(" > y : "); scanf("%f", &ret.supE.coord_y);

    printf("\n\n Coordenadas do ponto inferior direito:\n");
    printf(" > x : "); scanf("%f", &ret.infD.coord_x);
    printf(" > y : "); scanf("%f", &ret.infD.coord_y);

    // Calculando a dist�ncia entre os pontos da base
    base = abs(ret.supE.coord_x - ret.infD.coord_x);
    altura = abs(ret.supE.coord_y - ret.infD.coord_y);

    ret.area=base*altura;
    ret.perimetro=(2*base)+(2*altura);

    printf("\n �rea do ret�ngulo: %.2lf", ret.area);
    printf("\n Per�metro do ret�ngulo: %.2lf", ret.perimetro);

    printf("\n\n");
    return 0;
}
