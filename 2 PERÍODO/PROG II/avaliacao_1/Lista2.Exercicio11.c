/*
11. Faça um algoritmo para ler dois números inteiros e calcular e mostrar o valor
resultante se elevarmos a base representada pelo primeiro à potência representada pelo
segundo. Dica: busque qual a função que faz a potenciação.
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
