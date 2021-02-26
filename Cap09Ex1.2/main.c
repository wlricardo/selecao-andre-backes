/**
 *
 * Faça uma função que receba um número inteiro de 1 a 12 e imprima em tela o
 * mês e a sua quantidade de dias de acordo com o número digitado pelo usuário.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char mes[][10] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
                "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

void retorna_mes(int valor) {

    switch (valor)
    {
        case 1:
            printf("\n Janeiro\n");
        break;
        case 2:
            printf("\n Fevereiro\n");
        break;
        case 3:
            printf("\n Março\n");
        break;
    default:
            printf("\n Valor inválido \n");
        break;
    }

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int m;

    printf("\n Informe o mês desejado [1-12]:\n > ");
    scanf("%d", &m);

    retorna_mes(m);

    printf("\n\n");
    return 0;
}
