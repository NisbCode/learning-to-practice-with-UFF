/*
2. Faça uma função recursiva para imprimir a soma dos números ímpares de um vetor.
*/

#include <stdio.h>
#include <conio.h>
#define TAM 10

int somatorio(int n[], int tamanho, int i);

int main(void){
  int numero[TAM], soma, i;

  printf("Digite uma sequencia de numeros que deseja calcular, insira enter no final de cada um: ");
  for(i = 0; i < TAM; i++)
    scanf("%d", &numero[i]);

  soma = somatorio(numero, TAM, 0);

  printf("Soma dos valores impares = %d", soma);

  return 0;
}


int somatorio(int n[], int tamanho, int i){
    if(i == tamanho){
        return n[i];
    } else if(n[i] % 2 == 1){
        return n[i] + somatorio(n, tamanho, ++i);
    }else{
        somatorio(n, tamanho, ++i);
    }
}


