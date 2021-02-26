/**
 *
 * Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura
 * deve conter o número de matrícula do aluno, seu nome e as notas de três provas.
 * Agora, escreva um programa que leia os dados de cinco alunos e os armazena nessa
 * estrutura. Em seguida, exiba o nome e as notas do aluno que possui a maior média
 * geral dentre os cinco.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX 5
#define NOTAS 3

typedef struct {
    char matricula[11];
    char nome[50];
    float notas[NOTAS];
    float media;
} Aluno;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Aluno al[MAX];
    float maior;
    int indice;
    int i, j;

    // Criando estrutura dos dados dos alunos
    printf("\n Forneça os dados dos %d alunos:\n\n", MAX);
    for (i=0; i<MAX; i++) {
        al[i].media=0.0;
        printf("----------------------------------------------");
        printf("\n DADOS DO ALUNO %d/%d:\n", i+1, MAX);
        printf(" Matrícula...: "); gets(al[i].matricula);
        printf(" Nome........: "); gets(al[i].nome);
        for (j=0; j<NOTAS; j++) {
            al[i].notas[j] = 5 + rand()%5;
            printf("\n  Nota %d : %.2f", j+1, al[i].notas[j]);
            al[i].media += al[i].notas[j];
        }
        printf("\n [Média  : %.2f]\n", al[i].media/NOTAS);
    }
    printf("----------------------------------------------");

    // Obtendo o índice do aluno que obteve a maior nota
    maior = al[0].media;
    for (i=0; i<MAX; i++) {
        if (al[i].media >= maior) {
            maior=al[i].media;
            indice = i;
        }
    }
    printf("\n\n\n");
    printf(" DADOS DO ALUNO COM A MELHOR MÉDIA:\n");
    printf("\n MATRÍCULA..: %s", al[indice].matricula);
    printf("\n NOME.......: %s\n\n", al[indice].nome);
    for (i=0; i<NOTAS; i++) {
        printf(" [Nota 1: %.2f] ", al[indice].notas[i]);
    }

    printf("\n\n");
    return 0;
}
