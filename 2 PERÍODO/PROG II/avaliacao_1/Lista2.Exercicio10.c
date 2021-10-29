/*
10. O maior divisor comum (MDC) de dois números inteiros é o maior número inteiro
que faz uma divisão exata (com resto zero) desses dois números. Por exemplo, o MDC de
32 e 40 é 8, o MDC de 9 e 27 é 9 e o MDC de 13 e 25 é 1. Implemente uma função que
receba como parâmetros dois números inteiros x e y e calcule o MDC desses números.
Essa função deve ter o seguinte protótipo:
int mdc (int x, int y);
*/

#include <stdio.h>

int mdc(int x, int y);

int main(){

    int numero1, numero2;

    printf("Digite dois numeros para efetuarmos o Maior Divisor Comum: ");
    scanf("%d%d", &numero1, &numero2);
    int resultado = mdc(numero1, numero2);
    printf("%d", resultado);
}

int mdc(int x, int y){
    int resto = 0;
    do {
        resto = x % y;
        x = y;
        y = resto;
    }while(resto != 0);
    return x;
}
