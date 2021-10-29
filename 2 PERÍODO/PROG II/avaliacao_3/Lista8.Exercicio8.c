/*
Exercícios sobre Ordenação
1. Escreva uma função em C que receba um vetor de caracteres e faça a ordenação
desses elementos usando os métodos da Bolha e do QuickSort. Após finalizar esses
programas, utilize a função qsort do C para realizar a ordenação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10


/* FUNÇÃO PARA TROCAR OS ELEMENTOS DE UM VETOR COM TAL INDEX COM SEU ELEMENTO POSTERIOR */
static int separa(char letras[], char low, char high) {
    int c = letras[high];                                           // pivô
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
    if (low < high) {                                //Se p for menor que o pivô
        char j = separa(letras, low, high);            //Devemos trocar os elementos de v[j] e v[j + 1] de lugar, até o fim do array
        quickSort(letras, low, j - 1);             //E no array resultante, aplicamos o quicksort a esquerda do pivô
        quickSort(letras, j + 1, high);             //e a direita do pivô
    }
}



/* ORDENANDO POR BUBBLESORT */
int metodoBolha(char letras[], int aux, int contador){

    int i;
    printf("Ordem atual dos itens no array:\n");
    show(letras);

// Algoritmo de ordenação Bubblesort:
    for (contador = 1; contador < TAM; contador++){
        for (i = 0; i < TAM - 1; i++) {
            if (letras[i] > letras[i + 1]) {                //Se o número do primeiro index for maior que o do posterior a esse
                aux = letras[i];                            //Uma variável temporária receberá esse valor
                letras[i] = letras[i + 1];                  //O variável que antes tinha o maior valor irá receber o posterior que era menor
                letras[i + 1] = aux;                        //O posterior receberá a temporária que guardava a maior
            }                                               //Ao chegar ao fim, ele terá comparado todos os valores com seus posteriores, os ordenando
        }
    }

    return 0;
}



int show(char letras[]){                //Criei uma função apenas pra não ficar repetindo linhas de código
    for (int i = 0; i < TAM; i++)
        printf("%4c", letras[i]);
}



int main() {

    setlocale(LC_ALL, "");
    char letras[TAM+1];     //Guardando um espaço para o caracter especial enter
    int i, contador;
    char low, high, aux;

    printf("Entre com dez letras (SEM ESPAÇO) para preencher o array, e pressione enter apos digitar: ");
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
