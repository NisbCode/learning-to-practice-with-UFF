/*
1. Escreva um programa em C para ler um vetor X de 10 elementos inteiros. Logo após copie os
elementos do vetor X para um vetor Y fazendo com que o 1o. elemento de X seja copiado para o
10o. de Y, o 2o. de X para o 9o. de Y e assim sucessivamente. Após o término da cópia, imprimir o
vetor Y.
*/

#include <stdio.h>
#define DEFINIDOR 10


void leitor(int X[]){
    for(int i = 0; i < DEFINIDOR ; i++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &X[i]);
    }
}

void copy(int Y[], int X[]){
    int count;

    for(count = 0 ; count < DEFINIDOR ; count++)
        Y[DEFINIDOR - (count+1)] = X[count];
}

void show(int vet[]){
    int count;

    for(count = 0; count < DEFINIDOR ; count++)
        printf("%4d ", vet[count]);
}

int main(void){

    int X[DEFINIDOR], Y[DEFINIDOR];

    leitor(X);
    copy(Y, X);

    printf("\nVetor copiado e invertido: ");
    show(Y);

    return 0;
}
