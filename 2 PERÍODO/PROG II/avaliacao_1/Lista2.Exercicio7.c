/*
7. Escreva um programa que calcule o sal�rio semanal de um trabalhador. As entradas
s�o o n�mero de horas trabalhadas na semana e o valor da hora. At� 40 h/semana n�o se
acrescenta nenhum adicional. Acima de 40h e at� 60h h� um b�nus de 50% para essas
horas. Acima de 60h h� um b�nus de 100% para essas horas.
*/

#include <stdio.h>

int main(){

    int horas;
    float salario, valorHora;

    printf("Me diga quanto tempo o funcionario trabalhou essa semana: ");
    scanf("%d", &horas);
    printf("Me diga o valor de horas trabalhadas: ");
    scanf("%f", &valorHora);

    if(horas <= 40){
        salario = horas * valorHora;
        printf("O salario semanal desse trabalhador sera de R$%.2f.", salario);
    }else if((horas > 40) && (horas <= 60)){
        valorHora = valorHora * 0.5;
        salario = horas * valorHora;
        printf("O salario semanal desse trabalhador sera de R$%.2f.", salario);
    }else{
        valorHora = valorHora * 2;
        salario = horas * valorHora;
        printf("O salario semanal desse trabalhador sera de R$%.2f.", salario);
    }
    return 0;
}
