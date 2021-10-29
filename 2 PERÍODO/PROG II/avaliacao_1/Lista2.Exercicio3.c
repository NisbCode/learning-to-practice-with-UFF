/*
3. Faça um programa que imprima os n primeiros termos da série de Fibonacci,
lembrando que esta série é definida da seguinte forma:
termo1 = 1
termo2 = 1
termon = termon−1 + termon−2
O usuário do programa deve fornecer o número de termos, e estes devem ser impressos
separados por um espaço. Por exemplo, se o usuário pedir os 6 primeiros termos da série
de Fibonacci, o programa deve ter a seguinte saída:
1 1 2 3 5 8
*/

#include <stdio.h>

int main(){
    int quantidade;
    int contador = 1;
    int termo1 = 1;
    int termo2 = 1;

    printf("Informe a quantidade de termos: ");
    scanf("%d", &quantidade);

    for(contador; contador <= quantidade; contador++){
        printf("%d ", termo2);
        contador += 1;
        if(contador <= quantidade){
            printf("%d ", termo1);
            termo2 += termo1;
            termo1 = termo1 + termo2;
        }
    }
    return 0;
}
