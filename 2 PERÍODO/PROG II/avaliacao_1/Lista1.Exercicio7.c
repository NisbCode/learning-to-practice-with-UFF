/*
7. Fa�a opera��es de arredondamento para cima e para baixo com n�meros float. Dica:
Pesquise o documento �Cart�o de Refer�ncia da Linguagem C� para encontrar quais
fun��es devem ser usadas no programa.
*/

#include <stdio.h>
#include<conio.h>
#include <string.h>
#include <math.h>

int main(){
    float valor1;
    float valor2;
    char operador[2];
    float resultado;

    printf("Digite o primeiro valor: \n");
    scanf("%f", &valor1);
    printf("Informe a operacao: \n");
    scanf("%s", operador);
    printf("Digite o segundo valor: \n");
    scanf("%f", &valor2);

    if(strncmp(operador, "+", 1) == 0){
        resultado = valor1 + valor2;
    }
    if(strncmp(operador, "-", 1) == 0){
        resultado = valor1 - valor2;
    }
    if(strncmp(operador, "/", 1) == 0){
        resultado = valor1 / valor2;
    }
    if(strncmp(operador, "*", 1) == 0){
        resultado = valor1 * valor2;
    }
    printf("Resultado normal %f \n", resultado);
    printf("Resultado arredondado para baixo %.2f \n", floor(resultado));
    printf("Resultado arredondado para cima %.2f \n", ceil(resultado));
}
