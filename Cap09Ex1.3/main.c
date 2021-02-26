/**
 *
 * Escreva uma fun��o que receba por par�metro uma temperatura em graus Fahrenheit
 * e a retorne convertida em graus Celsius. A f�rmula de convers�o �: C = (F � 32.0) *
 * (5.0/9.0), sendo F a temperatura em Fahrenheit e C a temperatura em Celsius.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float F_2_C(float temp_f) {

    return ((temp_f - 32)*(5.0/9.0));
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float temp;

    printf("\n Temperatura em graus Fahrenheit: ");
    scanf("%f", &temp);
    printf("\n Temperatura em graus Celsius: %.2f", F_2_C(temp));

    printf("\n\n");
    return 0;
}
