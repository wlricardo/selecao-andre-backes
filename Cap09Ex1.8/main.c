/**
 *
 * Elabore uma função para verificar se um número é um quadrado perfeito. Um
 * quadrado perfeito é um número inteiro não negativo que pode ser expresso como
 * o quadrado de outro número inteiro. Exemplos: 1, 4, 9.
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

    printf("\n Informe o número desejado: ");
    scanf("%d", &valor);

    if (quadrado_perfeito(valor)) {
        printf("\n O número %d é quadrado perfeito.\n", valor);
    } else {
        printf("\n O número %d não é quadrado perfeito.\n", valor);
    }

    printf("\n\n");
    return 0;
}
