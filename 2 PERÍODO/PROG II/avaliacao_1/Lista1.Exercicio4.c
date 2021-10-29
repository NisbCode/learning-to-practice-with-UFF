/*
4. Um funcion�rio da UFF precisa validar as notas de 3 provas fornecidas por um
professor e indicar: a m�dia, se est� aprovado/reprovado e se tem direito de realizar a VS.
Inicialmente, fa�a um programa que recebe como entrada as 3 notas e mostre os
resultados solicitados. Posteriormente, coloque o c�digo de c�lculo da m�dia em uma
fun��o. Em um passo seguinte, realize os controles necess�rios para n�o receber notas
inv�lidas.
*/

#include <stdio.h>

void  media(nota1, nota2, nota3);       //�Prot�tipo� da fun��o: deve ser inclu�do antes da fun��o ser chamada
int main (void){

    int nota1, nota2, nota3;

    printf("Digite o resultado da primeira prova:\n");
    scanf("%d", &nota1);
    printf("Digite o resultado da segunda prova:\n");
    scanf("%d", &nota2);
    printf("Digite o resultado da terceira prova:\n");
    scanf("%d", &nota3);

    media(nota1, nota2, nota3);

    return 0;
}


/* fun��o para calcular m�dia de provas */
void media (int nota1, int nota2, int nota3){
    if((nota1 >= 0) && (nota1 <= 10) && (nota2 >= 0) && (nota2 <= 10) && (nota3 >= 0) && (nota3 <= 10)){

        float media = (nota1 + nota2 + nota3) / 3.0;    //For�ando para o resultado ser em float usando ".0" no 3

        printf("Media = %.2f \n", media);

        if(media >= 6){
            printf("Aprovado");
        }
        else if((media >= 4) && (media < 6)){
            printf("Tem direito a fazer a VS");
        }
        else{
            printf("Reprovado");
        }
    }
    else{
        printf("Notas invalidas");
    }
}

