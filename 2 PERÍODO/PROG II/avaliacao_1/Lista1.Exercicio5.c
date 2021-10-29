/*
5. Defina as variáveis a, b e c (tipo de dado) para obter todas as possíveis respostas para
os valores de ‘c’:
Suponha que:
a = 3
b = a / 2
c = b + 3.1
Valores possíveis para ‘c’?
1. c = 4.6
2. c = 4.1
3. c = 4
*/

#include <stdio.h>

int main(){

    float a;

    printf("Insira um valor que daremos suas possibilidades de resposta: ");
    scanf("%f", &a);


    float b = a / 2;
    float c = b + 3.1;
    int a_Int = (int)a;
    int b_Int = a_Int / 2;
    float c_Caso2 = b_Int + 3.1;
    int c_Int = b_Int + 3.1;

    printf("Se a, b e c = float: %.1f\n", c);
    printf("Se a, b = int e c = float: %.1f\n", (float)c_Caso2);
    printf("Se a, b e c = int: %d", c_Int);
}
