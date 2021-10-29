/*
2. Seja o seguinte trecho de programa:
int i=3,j=5;
int *p, *q;
p = &i;
q = &j;
Qual é o valor das seguintes expressões ?
a) p == &i; b) *p - *q c) **&p d) 3* - *p/(*q)+7
*/

#include <stdio.h>

int main(){
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;

    printf("A)\t%s\n", p == &i ? "true" : "false");     //Imprime verdadeiro, já que ambos falam do endereço
    printf("B)\t%d\n", *p - *q);         //Imprime "-2", a subtração dos valores
    printf("C)\t%d\n", **&p);            //No fim, ele retorna o valor "3" referenciado por ser uma referencia indireta
    printf("D)\t%d", 3* - *p/(*q)+7);    //Resultado é "6", explicação abaixo
    /*
    3* - *p/(*q)+7
    ^       ^
    |       |
    3*-3=-9 |
            -9/5=-1.8   <---Mas como é um inteiro, o resultado é apenas '-1'
            -1+7=6
    */

    return 0;
}
