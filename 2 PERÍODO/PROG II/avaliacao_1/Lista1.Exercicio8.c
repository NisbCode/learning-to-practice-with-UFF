/*
8. Considerando a existência de notas (cédulas) nos valores R$ 100, R$ 50, R$ 20, R$ 10,
R$ 5, R$ 2 e R$ 1, escreva um programa que capture um valor inteiro em reais (R$) e
determine o menor número de notas para se obter o montante fornecido. A função deve
ter o seguinte protótipo:
int total_de_notas(int valor);
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
    int dinheiro;

    printf("Me diga a quantidade de dinheiro que possui: ");
    scanf("%d", &dinheiro);

    if(dinheiro > 0){
        int cem = dinheiro / 100;
        printf("%d nota(s) de R$ 100,00\n", cem);
        dinheiro = abs(dinheiro - (cem*100));

        int cin = dinheiro / 50;
        printf("%d nota(s) de R$ 50,00\n", cin);
        dinheiro = abs(dinheiro - (cin*50));

        int vin = dinheiro / 20;
        printf("%d nota(s) de R$ 20,00\n", vin);
        dinheiro = abs(dinheiro - (vin*20));

        int dez = dinheiro / 10;
        printf("%d nota(s) de R$ 10,00\n", dez);
        dinheiro = abs(dinheiro - (dez*10));

        int cinco = dinheiro / 5;
        printf("%d nota(s) de R$ 5,00\n", cinco);
        dinheiro = abs(dinheiro - (cinco*5));

        int dois = dinheiro / 2;
        printf("%d nota(s) de R$ 2,00\n", dois);
        dinheiro = abs(dinheiro - (dois*2));

        int um = dinheiro / 1;
        printf("%d nota(s) de R$ 1,00\n", um);
        dinheiro = abs(dinheiro - (um*1));
    }
}
