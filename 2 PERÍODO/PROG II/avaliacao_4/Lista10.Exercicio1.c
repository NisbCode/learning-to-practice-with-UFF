/*
1) Considere o tipo Funcionario, que representa um funcion�rio de uma empresa,
definido pela estrutura a seguir:

struct funcionario {
char nome[81]; // nome do funcion�rio
float valor_hora; // valor da hora de trabalho em Reais
int horas_mes; // horas trabalhadas em um m�s
};
typedef struct funcionario Funcionario;

Escreva uma fun��o em C que preencha um vetor de ponteiros para Funcionario com os
dados lidos de um arquivo texto. Essa fun��o deve receber como par�metros o vetor de
ponteiros para Funcionario (representado pelo seu comprimento e pelo endere�o de seu
primeiro elemento) previamente alocado e o nome do arquivo de entrada. Nesse arquivo
de entrada, os dados de cada funcion�rio s�o armazenados em duas linhas: uma com o
seu nome (cadeia com at� 80 caracteres), e outra com o valor de sua hora de trabalho e
com o n�mero de horas trabalhadas em um m�s (nessa ordem). Um exemplo desse
formato � mostrado abaixo.

Jo�o da Silva
15.0 160
Manuel Santos
15.0 80
Fulana de Tal
23.5 40

Considere que: n�o existem linhas em branco no arquivo; o par�metro vet j� vem com
todas as suas posi��es inicializadas com NULL; o comprimento do vetor (par�metro n) �
no m�nimo igual � quantidade de registros de funcion�rios no arquivo de entrada; se n�o
for poss�vel abrir o arquivo, a fun��o deve imprimir a mensagem �ERRO� e terminar a
execu��o do programa. A fun��o implementada deve ter o seguinte prot�tipo:

void carrega (int n, Funcionario** vet, char* arquivo);
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 50


struct funcionario {
    char nome[81];
    float valor_hora;
    int horas_mes;

};
typedef struct funcionario Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo);




int main(void){
    struct Funcionario;
    Funcionario **vet[TAM];
    char *nome_arq = "func.txt";
    carrega(TAM,vet, nome_arq);

    return 0;
}




void carrega(int n, Funcionario** vet, char* arquivo){
    struct funcionario Funcionario;

    FILE *arq;
    arq = fopen(arquivo, "r");
    if(arq == NULL){
        printf("ERRO!!\n");
        exit(1);
    }

    while(fscanf(arq, " %80[^\n]", &Funcionario.nome) != EOF){
        fscanf(arq," %f %d", &Funcionario.valor_hora, &Funcionario.horas_mes);
        vet[0] = Funcionario.nome;
        printf("Nome: %s \nValor da hora: %.1f \nHoras trabalhadas no mes: %d\n\n\n", vet[0], Funcionario.valor_hora, Funcionario.horas_mes);
    }
    fclose(arq);
}
