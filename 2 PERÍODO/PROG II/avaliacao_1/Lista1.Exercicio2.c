/*
2. Fazer um programa que recebe 3 valores inteiros do usuário e mostra o maior deles, o
menor deles, os valores pares e a média.
*/

#include <stdio.h>

int main(){
    int valor1, valor2, valor3, pares, soma, maior, menor;
    float media;

    printf("Digite 3 valores para serem comparados \n---> ");
    scanf("%d", &valor1);
    printf("---> ");
    scanf("%d", &valor2);
    printf("---> ");
    scanf("%d", &valor3);

    //Maior
    if(valor1 > valor2){
        if(valor1 > valor3)
            maior = valor1;
    }
    if(valor2 > valor1){
        if(valor2 > valor3)
            maior = valor2;
    }
    if(valor3 > valor1){
        if(valor3 > valor2)
            maior = valor3;
    }

    //Menor
    if(valor1 < valor2){
        if(valor1 < valor3)
            menor = valor1;
    }
    if(valor2 < valor1){
        if(valor2 < valor3)
            menor = valor2;
    }
    if(valor3 < valor1){
        if(valor3 < valor2)
            menor = valor3;
    }

    //Média
    media = (valor1 + valor2 + valor3)/3.0;

    printf("O maior valor eh %d \n", maior);
    printf("O menor valor eh %d \n", menor);
    printf("A media eh %.2f \n", media);

    //Pares
    printf("Valor(es) par(es):");
    if(valor1%2 == 0){
        printf(" %d", valor1);
    }
    if(valor2%2 == 0){
        printf(" %d", valor2);
    }
    if(valor3%2 == 0){
        printf(" %d", valor3);
    }
}
