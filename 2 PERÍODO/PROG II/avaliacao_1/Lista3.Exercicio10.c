/*
10. Implemente um programa que chame a função média com o seguinte protótipo:
float media(int n, float *v)
*/

#include <stdio.h>
#include <math.h>

float media(int n, float *v);

int main(){

    int quantidade = 0;
    float notas[50] = {}, resultado = 0;      //Criando um vetor com capacidade de até 50 notas

    printf("Insira quantos numeros terao para a media: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade ; i++){
        resultado = media(quantidade, &notas[i]);
    }

    printf("\n\n==========================================\nA media eh: %.2f", resultado);
    return 0;
}

float media(int n, float *v){

    static int contador = 1;        //Mantendo o valor estático porque é algo sempre pertencente nesse método
    static float soma = 0;
    *v = rand() % 10;               //Tentando fazer algo diferente para aprender novas maneiras de manipular vetores.
                                    //Eu aleatorizei valores de notas entre 0 à 10 para preencher o vetor
    soma += *v;

    printf("Nota: %.2f foi aleatorizada para preencher esse vetor\n", *v);

    if (contador == n){
        return (soma / n);
    }
    else{
        contador++;
    }
}
