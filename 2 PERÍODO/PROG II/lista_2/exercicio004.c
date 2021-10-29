/*
4. Escreva um programa que sorteie uma letra do alfabeto de �a� a �z� e o usu�rio �
perguntado qual � essa letra. O programa deve informar se a letra � maior ou menor e
quando o usu�rio a acertou.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int i = 1;
    char letra;
    srand(time(NULL));
    int valorAleatorio;

    valorAleatorio = 97 + (rand() % 26);            //Fun��o respons�vel pela aleatoriza��o, como pega de 0 � ... Somamos 65
                                                    //Ao seu valor m�nimo e dividimos pelo intervalo de  valores que deve ir
                                                    //Nesse caso, deve ir de 65 at� 90, inclusos, mantendo assim 26 valores
                                                    //J� que 65 j� est� expl�cito

    printf("Tente adivinhar a letra entre 'a' e 'z' que estou pensando :p\n");
    scanf("%c", &letra);


    if(letra == valorAleatorio){
        printf("Voce acertou!");
    }
    else if(letra < valorAleatorio){
        printf("HA! PERDESTE! A letra pensada foi '%c', ela eh maior que a que pensou.", valorAleatorio);
    }
    else{
        printf("HA! PERDESTE! A letra pensada foi '%c', ela eh menor que a que pensou.", valorAleatorio);
    }
    return 0;
}
