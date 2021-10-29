/*
12. Fazer um programa para receber uma frase do usuário, caracter a caracter usando getch() e
armazenando no vetor (máx. 80 caracteres). Quando o usuário digita enter (‘\r’) a recepção é
finalizada. Mostrar cada palavra da frase em uma linha separada
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(){

    char phrase[80], letter;
    int i = 0, cont = 0;

    printf("Insira sua frase: ");

    do{
        letter = getch();
        phrase[i] = letter;
        printf("%c", phrase[i]);
        i++;

    }while(letter != 0xD);

    printf("A frase dividida fica assim: \n");

    do{
        if (phrase[cont] != 0x20){
            printf("%c", phrase[cont]);
        }
        else{
            printf("\n");
        }
        cont++;

    }while(phrase[cont] != 0xD);
    return 0;
}
