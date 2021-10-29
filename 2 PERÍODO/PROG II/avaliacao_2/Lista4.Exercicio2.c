/*
2. Escreva um programa em C para ler um vetor R (de 5 elementos) e um vetor S (de 10
elementos). Gere um vetor X que possua os elementos comuns a R e a S. Considere que pode
existir repetição de elementos no mesmo vetor. Nesta situação somente uma ocorrência do
elemento comum aos dois deve ser copiada para o vetor X. Após o término da cópia, escrever o
vetor X.
*/

#include <stdio.h>
#define DEFINIDOR 5
#define DEFINIDOR2 10


void leitor(int R[], int S[]){
    printf("==========Primeiro vetor (5 elementos)==========\n\n");
    for(int i = 0; i < DEFINIDOR ; i++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &R[i]);
    }

    printf("==========Segundo vetor (10 elementos)==========\n\n");
    for(int i = 0; i < DEFINIDOR2 ; i++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &S[i]);
    }
}

void duplicados(int S[], int R[], int X[]){
    int contador = 0;

    for(int i = 0; i < DEFINIDOR2; i++){
        for(int count = 0; count < DEFINIDOR; count++){
            if(R[count] == S[i]){
                X[contador] = R[count];
                contador++;
            }
        }
    }
}

int main(void){

    int R[DEFINIDOR], S[DEFINIDOR2], X[10] = {}, count;

    leitor(R, S);
    duplicados(S, R, X);

    printf("Vetor principal: ");
    for(count = 0 ; count < DEFINIDOR ; count++)
        printf("%4d ", R[count]);

    printf("\nVetor secundario: ");
    for(count = 0 ; count < DEFINIDOR2 ; count++)
        printf("%4d ", S[count]);

    printf("\nVetor duplicado: ");
    for(count = 0 ; count < DEFINIDOR2 ; count++)
        printf("%4d ", X[count]);

    return 0;
}
