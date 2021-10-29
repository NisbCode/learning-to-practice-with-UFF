/*
6. Fazer um programa que sorteie um n�mero de 0 a 100 e que permita que o usu�rio
(sem conhecer o n�mero sorteado) tente acertar. Caso n�o acerte, o programa deve
imprimir uma mensagem informando se o n�mero sorteado � maior ou menor que a
tentativa feita. Ao acertar o n�mero, o programa deve imprimir a quantidade de tentativas
feitas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int numeroSorteado = rand() % 101, tentativa, quantidade = 0;

    printf("Tente adivinhar qual numero de 0 a 100 que estou pensando :)\n");
    scanf("%d", &tentativa);

    while(tentativa != numeroSorteado){
        quantidade += 1;
        if(tentativa > numeroSorteado){
            printf("Puxa, na verdade o numero pensado eh MENOR que %d. Tente de novo: ", tentativa);
            scanf("%d", &tentativa);
        }else{
            printf("Puxa, na verdade o numero pensado eh MAIOR que %d. Tente de novo: ", tentativa);
            scanf("%d", &tentativa);
        }
    }
    printf("Parabens! Voce acertou com um total de %d tentativas :p", quantidade);
    return 0;
}
