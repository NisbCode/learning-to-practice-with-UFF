/*
2. Fa�a um programa que calcule e imprima a soma dos n primeiros n�meros naturais
�mpares. O usu�rio do programa deve fornecer quantos n�meros devem ser somados.
*/


#include <stdio.h>

int main(){
    int quantidade;
    int contador = 1;
    int soma = 0;

    printf("Informe quantos numeros impares serao somados: ");
    scanf("%d", &quantidade);

    for(contador; contador <= quantidade; contador++){
        if(contador%2 == 1){
            soma = soma + contador;
        }else{
            quantidade = quantidade + 1;
        }
    }
    printf("SOMA DOS VALORES IMPARES = %d", soma);
    return 0;
}
