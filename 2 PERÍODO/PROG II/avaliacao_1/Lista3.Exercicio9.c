/*
9. Assumindo que pulo[] � um vetor do tipo int, quais das seguintes express�es referenciam o valor
do terceiro elemento da matriz?
a) *(pulo + 2) b) *(pulo + 4) c) pulo + 4 d) pulo + 2
*/

#include <stdio.h>

int main(){

    char pulo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Letra A (X). Ex. com *(pulo + 2): %d\n", *(pulo + 2));//Com a letra A, o valor retornado ser� o terceiro da matriz
    printf("Letra B. Ex. com *(pulo + 4): %d\n", *(pulo + 4));
    printf("Letra C. Ex. com pulo + 4: %d\n", pulo + 4);
    printf("Letra D. Ex. com pulo + 2: %d\n", pulo + 2);

    return 0;
}
