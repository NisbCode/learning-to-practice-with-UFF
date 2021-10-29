/*
13. Fazer um programa para:
a. declarar vari�veis a, b, c, d do tipo int.
b. declarar vari�veis e, f, g, h do tipo float.
c. declarar vetor v de 10 elementos do tipo char.
d. declarar vari�vel x do tipo int.
e. criar um ponteiro apontando para o endere�o de a.
f. incrementar o ponteiro, mostrando o conte�do do endere�o apontado (em forma de n�mero).
Caso o endere�o coincida com o endere�o de alguma outra vari�vel, informar o fato.
*/

#include <stdio.h>

int main(){

    int a = 2, b = 3, c = 4, d = 5;
    float e = 6.2, f = 7.2, g = 8.2, h = 9.2;
    char v[10];
    int x = 10, *p;
    p = &a;

    printf("Antes de incrementar: %i \n", p);
    printf("O valor de p: %i \n", *p);

    p++;

    printf("Depois de incrementar: %i \n", p);
    printf("O valor de p: %i \n", *p);

    p++;

    printf("Incrementando de novo: %i \n", p);
    printf("O valor de p: %i \n", *p);

    if (*p == a ||*p == b ||*p == c ||*p == d ||*p == e ||*p == f ||*p == g ||*p == h ||*p == x ){
        printf("Teve semelhan�as no endere�o com o endere�o de outra variavel");
    }
    return 0;
}
