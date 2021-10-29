/*
3. Uma instituição de pesquisa recolheu amostras de estados brasileiros a respeito do
salário da população. Tendo o seguinte código:

......

a. Implemente a função cadastra, que atribui os parâmetros recebidos aos campos da
estrutura Assalariados.

b. Implemente a função imprime, que imprime todos os elementos do vetor de
Assalariados.

c. Implemente a função relatório, que imprime a quantidade de homens por estado com
mais de 40 anos que recebem salários superiores a R$ 1000,00....
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * estado[27] = {"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
char nome[51];
char sexo;
int idade;
float salario;
char estado[3];
} Assalariados;

Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado){
    Assalariados * assal;
    assal = (Assalariados *) malloc (sizeof(Assalariados));
    if (assal == NULL)
        printf("Nao foi possivel completar a operacao.\n");

    for (int i=0;i<51;i++){
        if(nome[i] == '\0'){
            assal->nome[i] = '\0';
            break;
        }
        assal->nome[i] = nome[i];
    }

    assal->sexo = sexo;
    assal->idade = idade;
    assal->salario = salario;

    for (int i = 0; i < 2; i++)
        assal->estado[i] = estado[i];

    assal->estado[2] = '\0';

    return assal;
}



void relatorio(Assalariados ** ptr, int numAssalariados){
    int quantidade = 0, conteudo_cacelar = 0, valor =0;
    char cancel[50][3];


    for (int i = 0; i < numAssalariados; i++){
        for (int cont = 0; cont < conteudo_cacelar; cont++){
    if(cancel[cont][0] == ptr[i]->estado[0] && cancel[cont][1] == ptr[i]->estado[1])
                valor = 1;

        }
        if (valor != 1){
            if (ptr[i]->idade > 40 && ptr[i]->salario > 1000){
                quantidade++;
                strcpy(cancel[conteudo_cacelar], ptr[i]->estado);

                for (int z = i + 1; z < numAssalariados; z++){
                    if (ptr[z]->idade > 40 && ptr[z]->salario > 1000 && ptr[i]->estado[0] == ptr[z]->estado[0] && ptr[i]->estado[1] == ptr[z]->estado[1])
                        quantidade++;
                }
            }
            if (quantidade > 0)
                printf("Estado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n", ptr[i]->estado, quantidade);

            conteudo_cacelar++;
        }
        quantidade = 0;
    }
}



void imprime(Assalariados ** ptr, int numAssalariados){
    for (int i = 0; i< numAssalariados; i++){
        printf("================= ASSALARIADO %d =================\n", i+1);
        printf("Nome: %s\nSexo: %c\nIdade: %d\nSalario: %.2f\nEstado: %s\n", ptr[i]->nome, ptr[i]->sexo, ptr[i]->idade, ptr[i]->salario, ptr[i]->estado);
    }
}



void main(void) {
    Assalariados **pessoas;
    int numAssalariados = 3;
    pessoas = (Assalariados **) malloc (numAssalariados * sizeof(Assalariados *));

    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");

    imprime(pessoas, numAssalariados);

    printf("\n\n\n================= RELATORIO =================\n");
    relatorio(pessoas,numAssalariados);
}

