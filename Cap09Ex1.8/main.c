/**
 *
 * Elabore uma fun��o para verificar se um n�mero � um quadrado perfeito. Um
 * quadrado perfeito � um n�mero inteiro n�o negativo que pode ser expresso como
 * o quadrado de outro n�mero inteiro. Exemplos: 1, 4, 9.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int quadrado_perfeito(int valor) {
    int i;

    for (i=1; i <= valor/2; i++) {
        if (i*i == valor) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int valor;

    printf("\n Informe o n�mero desejado: ");
    scanf("%d", &valor);

    if (quadrado_perfeito(valor)) {
        printf("\n O n�mero %d � quadrado perfeito.\n", valor);
    } else {
        printf("\n O n�mero %d n�o � quadrado perfeito.\n", valor);
    }

    printf("\n\n");
    return 0;
}
