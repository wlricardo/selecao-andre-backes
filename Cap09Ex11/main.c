/**
 *
 * Escreva uma função que receba por parâmetros dois valores inteiros x e y e calcule
 * e retorne o resultado de x y para o programa principal. Não use nenhuma função
 * pronta para isso.Escreva uma função que receba por parâmetros dois valores inteiros x e y e calcule
 * e retorne o resultado de x y para o programa principal. Não use nenhuma função
 * pronta para isso.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 3

long potencia(int base, int expoente) {
    int i;
    long pot=1;

    for (i=0; i<expoente; i++) {
        pot *= base;
    }
    return pot;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int base, expoente;
    long p;

    printf("\n Informe a base: ");
    scanf("%d", &base);

    printf(" Informe o expoente: ");
    scanf("%d", &expoente);

    p = potencia(base, expoente);
    printf("\n\n %d ^ %d = %ld\n", base, expoente, p);

    printf("\n\n");
    return 0;
}
