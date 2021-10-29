/*
5) Escreva um programa que leia de um arquivo, cujo nome será fornecido pelo usuário,
um conjunto de números reais e armazene em um vetor. O programa ao final calcula a
media dos números lidos.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10


int main(){

    FILE *arq;
    char nome[50];
    float numeros[50];
    char *result;
    float soma;
    float media;
    int i;

    printf("Diga o nome do arquivo que deseja criar: ");
    scanf("%s", nome);

    printf("Insira %d numeros reais ao arquivo criado e envie cada um usando ENTER: ", TAM);
    for(i = 0; i < TAM; i++){
        scanf("%f", &numeros[i]);
        soma += numeros[i];
    }
    media = soma / TAM;

    printf("Nome do arquivo: %s \n", nome);
    arq = fopen(nome, "wt");                                //Criando arquivo


    if (arq == NULL)
        printf("Problemas na CRIACAO do arquivo\n");

    for (i = 0; i < TAM;i++){
        result = fprintf(arq, "%f\n", numeros[i]);
        if (result == EOF)
            printf("Erro na Gravacao\n");
    }

    printf("A media dos valores colocados no arquivo eh: %.2f", media);

    fclose(arq);
    return 0;
}
