/*
1. Implemente a função calcula_circulo, que calcula a área e a circunferência de um círculo de raio
r. Essa função deve obedecer o protótipo:
void calc_circulo(float r, float * circunferencia, float * area);
Fórmulas:
A = π r²;
c = 2 π r ;
π = 3.14159265
Note que essa passagem dos 2 últimos parâmetros é uma passagem por referência.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_circuito(float r, float *circunferencia, float *area);

int main(){

    float raio, circunf, ar;


    printf("Me diga qual o valor do raio: ");
    scanf("%f", &raio);

    calcula_circuito(raio, &circunf, &ar);
    printf("Area: %.2f\nCircunferencia: %.2f", circunf, ar);

    return 0;
}

void calcula_circuito(float r, float *circunferencia, float *area){
    float pi = 3.14159265;
    *circunferencia = 2 * pi * r;
    *area = pi * pow(r, 2);
}
