/*
11. Fa�a um algoritmo para ler dois n�meros inteiros e calcular e mostrar o valor
resultante se elevarmos a base representada pelo primeiro � pot�ncia representada pelo
segundo. Dica: busque qual a fun��o que faz a potencia��o.
*/

#include <stdio.h>
#include <math.h>

int main(){

    int numero1, numero2;

    printf("Digite dois numeros para efetuarmos o Maior Divisor Comum: ");
    scanf("%d%d", &numero1, &numero2);

    int potencia = pow(numero1, numero2);
    printf("%d", potencia);
    return 0;
}
