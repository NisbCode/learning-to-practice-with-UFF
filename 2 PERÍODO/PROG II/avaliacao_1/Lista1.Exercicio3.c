/*
3. Fazer um programa que recebe um s�mbolo de opera��o do usu�rio (+, -, / ou *) e dois
n�meros reais. O programa deve retornar o resultado da opera��o recebida sobre estes
dois n�meros.
*/

#include <stdio.h>
#include<conio.h>
#include <string.h>

int main(){
    float valor1;
    float valor2;
    char operador[2];
    float resultado;

    printf("Digite o primeiro valor: \n");
    scanf("%f", &valor1);
    printf("Informe a operacao(+ - * /): \n");
    scanf("%s", operador);
    printf("Digite o segundo valor: \n");
    scanf("%f", &valor2);

    if(strncmp(operador, "+", 1) == 0){
        resultado = valor1 + valor2;
    }
    if(strncmp(operador, "-", 1) == 0){
        resultado = valor1 - valor2;
    }
    if(strncmp(operador, "/", 1) == 0){
        resultado = valor1 / valor2;
    }
    if(strncmp(operador, "*", 1) == 0){
        resultado = valor1 * valor2;
    }
    printf("%.2f", resultado);
}
