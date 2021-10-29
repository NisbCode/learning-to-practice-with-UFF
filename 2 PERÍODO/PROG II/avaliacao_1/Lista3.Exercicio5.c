/*
5. Implemente a fun��o max_vet, que recebe como par�metro um vetor de n�meros de ponto
flutuante (vet) de tamanho n e retorna o maior n�mero armazenado nesse vetor. Essa fun��o deve
obedecer o prot�tipo: float max_vet (int n, float * vet);
Fa�a tamb�m a fun��o main.
*/

#include <stdio.h>
#include <stdlib.h>

float max_vet (int n, float *vet);

int main(){

    int i, quantidade;
    float numeros[50], resultado;


    printf("Insira uma quantidade de numeros que terao: ");
    scanf("%d", &quantidade);
    for (i = 0; i < quantidade; i++){
        printf("Insira uma sequencia de valores para determinarmos qual eh o maior: \n");
        scanf("%f", &numeros[i]);
    }

    resultado = max_vet(quantidade, &numeros);
    printf("\n\n======================================\nMaior valor escrito: %.3f", resultado);
}

float max_vet (int n, float *vet){
    static int i;
    static float maior;

    for (i = 0; i < n; i++){
        if(i==0){
            maior = vet[i];
        }
        if(vet[i] > maior){
        maior=vet[i];
        }
    }
    return maior;
}
