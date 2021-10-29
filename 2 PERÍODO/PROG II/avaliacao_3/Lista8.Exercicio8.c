/*
Exerc�cios sobre Ordena��o
1. Escreva uma fun��o em C que receba um vetor de caracteres e fa�a a ordena��o
desses elementos usando os m�todos da Bolha e do QuickSort. Ap�s finalizar esses
programas, utilize a fun��o qsort do C para realizar a ordena��o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10


/* FUN��O PARA TROCAR OS ELEMENTOS DE UM VETOR COM TAL INDEX COM SEU ELEMENTO POSTERIOR */
static int separa(char letras[], char low, char high) {
    int c = letras[high];                                           // piv�
    char t, j = low;
    for (int k = low; k < high; ++k){
        if (letras[k] <= c) {
            t = letras[j], letras[j] = letras[k], letras[k] = t;
            ++j;
        }
    }
    t = letras[j], letras[j] = letras[high], letras[high] = t;
    return j;
}



/* ORDENANDO POR QUICKSORT */
void quickSort(char letras[], char low, char high) {
    if (low < high) {                                //Se p for menor que o piv�
        char j = separa(letras, low, high);            //Devemos trocar os elementos de v[j] e v[j + 1] de lugar, at� o fim do array
        quickSort(letras, low, j - 1);             //E no array resultante, aplicamos o quicksort a esquerda do piv�
        quickSort(letras, j + 1, high);             //e a direita do piv�
    }
}



/* ORDENANDO POR BUBBLESORT */
int metodoBolha(char letras[], int aux, int contador){

    int i;
    printf("Ordem atual dos itens no array:\n");
    show(letras);

// Algoritmo de ordena��o Bubblesort:
    for (contador = 1; contador < TAM; contador++){
        for (i = 0; i < TAM - 1; i++) {
            if (letras[i] > letras[i + 1]) {                //Se o n�mero do primeiro index for maior que o do posterior a esse
                aux = letras[i];                            //Uma vari�vel tempor�ria receber� esse valor
                letras[i] = letras[i + 1];                  //O vari�vel que antes tinha o maior valor ir� receber o posterior que era menor
                letras[i + 1] = aux;                        //O posterior receber� a tempor�ria que guardava a maior
            }                                               //Ao chegar ao fim, ele ter� comparado todos os valores com seus posteriores, os ordenando
        }
    }

    return 0;
}



int show(char letras[]){                //Criei uma fun��o apenas pra n�o ficar repetindo linhas de c�digo
    for (int i = 0; i < TAM; i++)
        printf("%4c", letras[i]);
}



int main() {

    setlocale(LC_ALL, "");
    char letras[TAM+1];     //Guardando um espa�o para o caracter especial enter
    int i, contador;
    char low, high, aux;

    printf("Entre com dez letras (SEM ESPA�O) para preencher o array, e pressione enter apos digitar: ");
    scanf("%s", &letras[i]);


    // Bubblesort
    metodoBolha(letras, aux, contador);
    printf("\nElementos do array em ordem crescente BubbleSort:\n");
    show(letras);


    quickSort(letras, low, high);              //precisamos desses valores para o programa comparar os valores com esses


    printf("\nElementos do array em ordem crescente QuickSort:\n");
    show(letras);

    return 0;
}
