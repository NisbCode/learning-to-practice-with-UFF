/*
13. Fazer um programa para:
a. declarar variáveis a, b, c, d do tipo int.
b. declarar variáveis e, f, g, h do tipo float.
c. declarar vetor v de 10 elementos do tipo char.
d. declarar variável x do tipo int.
e. criar um ponteiro apontando para o endereço de a.
f. incrementar o ponteiro, mostrando o conteúdo do endereço apontado (em forma de número).
Caso o endereço coincida com o endereço de alguma outra variável, informar o fato.
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
        printf("Teve semelhanças no endereço com o endereço de outra variavel");
    }
    return 0;
}
