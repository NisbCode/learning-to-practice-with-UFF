/*
7) Um arquivo do tipo texto, chamado ‘‘numeros.txt’’ contém uma quantidade
desconhecida de números reais. Escreva um programa que leia estes números, os coloque
em ordem crescente e depois os grave em um arquivo binário chamado ‘‘numeros.bin’’.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE *arq, *fl;
    char *numerosEmChar;
    float *numeros;
    char *result;
    float aux = 0;
    int i = 0, j = 0, quantidade = 0;



    arq = fopen("numeros.txt", "r");
    fl = fopen("numeros.bin", "w");

    printf("Digite quantos numeros existem no arquivo: ");
    scanf("%d", &quantidade);
    numeros = malloc (quantidade * sizeof(float));
    numerosEmChar = malloc (quantidade * sizeof(char));

    if (arq == NULL)
        printf("Problemas na LEITURA do arquivo\n");
    if (fl == NULL)
        printf("Problemas na CRIACAO do arquivo\n");

    while ((fgets(numerosEmChar, sizeof(arq), arq)) != NULL) {
        numeros[i] = atof(numerosEmChar);
        i++;
    }


    for(i = 0; i < quantidade; i++){
        for(j = i+1; j < quantidade; j++){
            if(numeros[i] > numeros[j]){
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }
    printf("ORDENADOS\n");
    for(i = 0; i < quantidade; i++)
        printf("%f \n", numeros[i]);



    for (i = 0; i < quantidade; i++){
        result = fprintf(fl, "%f\n", numeros[i]);
        if(result == EOF)
            printf("Erro na Gravacao\n");
    }

    return 0;
}


