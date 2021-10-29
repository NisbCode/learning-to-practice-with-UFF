/*
1) Considere o tipo Funcionario, que representa um funcionário de uma empresa,
definido pela estrutura a seguir:

struct funcionario {
char nome[81]; // nome do funcionário
float valor_hora; // valor da hora de trabalho em Reais
int horas_mes; // horas trabalhadas em um mês
};
typedef struct funcionario Funcionario;

Escreva uma função em C que preencha um vetor de ponteiros para Funcionario com os
dados lidos de um arquivo texto. Essa função deve receber como parâmetros o vetor de
ponteiros para Funcionario (representado pelo seu comprimento e pelo endereço de seu
primeiro elemento) previamente alocado e o nome do arquivo de entrada. Nesse arquivo
de entrada, os dados de cada funcionário são armazenados em duas linhas: uma com o
seu nome (cadeia com até 80 caracteres), e outra com o valor de sua hora de trabalho e
com o número de horas trabalhadas em um mês (nessa ordem). Um exemplo desse
formato é mostrado abaixo.

João da Silva
15.0 160
Manuel Santos
15.0 80
Fulana de Tal
23.5 40

Considere que: não existem linhas em branco no arquivo; o parâmetro vet já vem com
todas as suas posições inicializadas com NULL; o comprimento do vetor (parâmetro n) é
no mínimo igual à quantidade de registros de funcionários no arquivo de entrada; se não
for possível abrir o arquivo, a função deve imprimir a mensagem “ERRO” e terminar a
execução do programa. A função implementada deve ter o seguinte protótipo:

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
