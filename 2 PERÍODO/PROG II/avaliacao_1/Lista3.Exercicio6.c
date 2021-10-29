/*
6. Implemente a fun��o maiores, que recebe como par�metro um vetor de n�meros inteiros (vet) de
tamanho n e um valor x. A fun��o deve retornar quantos n�meros maiores do que x existem nesse
vetor. Essa fun��o deve obedecer ao prot�tipo:
int maiores(int n, int * vet, int x);
*/

#include <stdio.h>
#include <stdlib.h>

int maiores(int n, int * vet, int x);


int main(){

    int i, quantidade, numeros[50], comparador, resultado;

    printf("Insira um valor a ser comparado: ");
    scanf("%d", &comparador);
    printf("Insira uma quantidade de numeros que terao: ");
    scanf("%d", &quantidade);
    for (i = 0; i < quantidade; i++){
        printf("Insira uma sequencia de valores para determinarmos qual eh o maior: \n");
        scanf("%d", &numeros[i]);
    }

    resultado = maiores(quantidade, numeros, comparador);
    printf("\n\n======================================\nTemos %d valor(es) maior(es) que o valor escrito", resultado);
    return 0;
}

int maiores(int n, int *vet, int x){
    int i;
    int maior = 0;

    for (i = 0; i < n; i++){
        if(vet[i]>x){
            maior++;
        }
    }
    return maior;
}

