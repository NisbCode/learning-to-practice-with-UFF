/*
7. Seja a seguinte sequ�ncia de instru��es em um programa C:
int *pti;
int veti[]={10,7,2,6,3};
pti = veti;
Qual afirmativa � falsa?
a. *pti � igual a 10
b. *(pti+2) � igual a 2
c. pti[4] � igual a 3
d. pti[1] � igual a 10      //Pela ordem come�ar com 0, a casa 1 teria o valor 7, n�o 10
e. *(veti+3) � igual a 6
*/

#include <stdio.h>

int main(){

    int *pti;
    int veti[]={10,7,2,6,3};
    pti = veti;

    printf("%d seria o valor real", pti[1]);
}
