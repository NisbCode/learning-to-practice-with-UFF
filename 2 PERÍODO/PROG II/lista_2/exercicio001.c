/*
1. Fa�a um programa que verifique se um determinado n�mero � primo. O n�mero a ser
testado deve ser fornecido pelo usu�rio do programa. O programa deve imprimir a
mensagem �NUMERO PRIMO� caso o n�mero seja primo, e �NUMERO NAO PRIMO�
caso contr�rio.
*/

#include <stdio.h>

int main(){

    int numeroPrimo;

    printf("Diga um numero que informaremos se ele eh um numero primo\n");
    scanf("%d", &numeroPrimo);


    //SOMANDO ALGORITMOS DA VARI�VEL PARA A VALIDA��O DE SER DIVIDIDO POR 3
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

