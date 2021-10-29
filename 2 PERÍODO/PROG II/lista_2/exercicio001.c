/*
1. Faça um programa que verifique se um determinado número é primo. O número a ser
testado deve ser fornecido pelo usuário do programa. O programa deve imprimir a
mensagem “NUMERO PRIMO” caso o número seja primo, e “NUMERO NAO PRIMO”
caso contrário.
*/

#include <stdio.h>

int main(){

    int numeroPrimo;

    printf("Diga um numero que informaremos se ele eh um numero primo\n");
    scanf("%d", &numeroPrimo);


    //SOMANDO ALGORITMOS DA VARIÁVEL PARA A VALIDAÇÃO DE SER DIVIDIDO POR 3
    int validadorDeTres = numeroPrimo;
    int divisaoTres;
    int soma;

    while(validadorDeTres > 0){
    divisaoTres = validadorDeTres%10;
    soma = soma + divisaoTres;
    validadorDeTres = validadorDeTres / 10;
    }



    if((numeroPrimo > 1) && ((numeroPrimo%2 != 0) || (numeroPrimo == 2)) && ((soma%3 != 0) || (numeroPrimo == 3)) && ((numeroPrimo%10 != 5) ||(numeroPrimo == 5)) && ((numeroPrimo%7 != 0) || (numeroPrimo == 7))){
        printf("%d EH NUMERO PRIMO", numeroPrimo);
    }
    else{
        printf("%d NAO EH NUMERO PRIMO", numeroPrimo);
    }
    return 0;
}

