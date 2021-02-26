/**
 *
 * Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a idade
 * e o endere�o de uma pessoa. Agora, escreva uma fun��o que receba um inteiro
 * positivo N e retorne o ponteiro para um vetor de tamanho N, alocado dinamicamente,
 * dessa estrutura. Solicite tamb�m que o usu�rio digite os dados desse vetor
 * dentro da fun��o.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100

typedef struct {
    char nome[MAX];
    int idade;
    char endereco[3*MAX];
} Cadastro;

Cadastro* cadastro_clientes(int qtde_clientes) {

    Cadastro *c;
    int i;

    c = (Cadastro*)calloc(qtde_clientes, sizeof(Cadastro));
    if (c == NULL) {
        printf("\n\n Erro de aloca��o de mem�ria !\n\n");
    }
    for (i=0; i<qtde_clientes; i++) {
        printf("\n CLIENTE %2d:\n", i+1);
        printf("------------------");
        printf("\n Nome: "); gets(c->nome);
        fflush(stdin);
        printf(" Idade: "); scanf("%d", &c->idade);
        fflush(stdin);
        printf(" Endere�o: "); gets(c->endereco);
        fflush(stdin);
        printf("\n");
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Cadastro *c;
    int i, n;

    printf("\n Informe quantos clientes deseja cadastrar: ");
    scanf("%d", &n); fflush(stdin);

    c = cadastro_clientes(n);
    system("cls");
    printf("\n\n Clientes cadastrados com sucesso !!\n\n");
    getchar();

    for (i=0; i<n; i++) {
        printf("\n CLIENTE %2d:\n", i+1);
        printf("------------------");
        printf("\n Nome: %s", c->nome);
        printf("\n Idade: %2d", c->idade);
        printf("\n  Endere�o: %s", c->endereco);
        printf("\n");
    }

    printf("\n\n");
    return 0;
}
