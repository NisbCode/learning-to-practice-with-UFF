/*
8. Qual é o resultado do seguinte programa?
#include <conio.h>
#include <stdio.h>
void main(){
float vet[5] = {1.1,2.2,3.3,4.4,5.5};
float *f;
int i;
f = vet;
printf("contador/valor/valor/endereco/endereco");
for(i = 0 ; i <= 4 ; i++){
printf("\ni = %d",i);
printf(" vet[%d] = %.1f",i, vet[i]);
printf(" *(f + %d) = %.1f",i, *(f+i));
printf(" &vet[%d] = %X",i, &vet[i]);
printf(" (f + %d) = %X",i, f+i);
}
}
*/

#include <conio.h>
#include <stdio.h>
void main(){

    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;

    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++){
        printf("\ni = %d",i);                   //<--- A primeira parte vai ser a contagem do vetor
        printf(" vet[%d] = %.1f",i, vet[i]);    //<--- Valor do vetor no número da contagem do i e o índice em questão
        printf(" *(f + %d) = %.1f",i, *(f+i));  //<--- O valor dentro do endereço de memória de f+i (f mais o contador)
        printf(" &vet[%d] = %X",i, &vet[i]);    //<--- Endereço de memória do vetor na contagem que estará o contador
        printf(" (f + %d) = %X",i, f+i);        //<--- O  endereço de memória do ponteiro f+i (f mais o contador)
        //Tudo (exceto o primeito "printf" ocorrerá na mesma linha já que não temos um \n.
        //Ou seja, em cada passagem do for, isso executará na mesma linha por 5 linhas (determinado pelo i<=4 do for)
    }
}
