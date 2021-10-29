/*
1. Fazer um programa para receber um número inteiro de segundos do usuário e imprimir
a quantidade correspondente em horas, minutos e segundos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int segundos;

  printf("Segundos que serao convertidos: ");
  scanf("%d", &segundos);

  int horas = (int) segundos/(60*60);
  int resto = segundos%(60*60);
  int minutos = (int) segundos/60;
  resto = resto%60;
  int seg = resto;

  printf("Segundos inseridos: %i\n", segundos);
  printf("Horas: %d Minutos: %d Segundos: %d", horas, minutos, seg);

  return 0;
}
