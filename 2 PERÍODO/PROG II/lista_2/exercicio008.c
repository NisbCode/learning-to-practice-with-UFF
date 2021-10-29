/*
8. O n�mero 3025 possui a seguinte caracter�stica: 30 + 25 = 55 -> 55*55 = 3025. Fazer
um programa para obter todos os n�meros de 4 algarismos com a mesma caracter�stica do
n�mero 3025.
*/


#include <stdio.h>

int main(){

    int i = 1000, soma, resto;

    if((1000 <= i) || (i <= 9999)){
            printf("Dentre 1000 e 9999\n\n");
        for(i; i <= 9999; i++){
            resto = i;
            soma = 0;
            while (resto > 0){
                soma = soma + (resto % 100);
                resto /= 100;
            }
            if(soma * soma == i){
                printf("O numero %d\n", i);
            }
        }
    }
    return 0;
}
