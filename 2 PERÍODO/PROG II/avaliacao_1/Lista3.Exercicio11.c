/*
11. Escreva um programa que realize a leitura da idade, da altura e do sexo de n pessoas. Ao final,
mostre o número de mulheres com idade entre 20 e 35 anos e o número de homens com altura
maior que 1,80m. Calcule e mostre também a variância da altura.
*/

#include <stdio.h>
#include <math.h>

int main(){

    int contador = 0, idade = 0, mulher = 0,  homem = 0, resultado = 1;
    float altura = 0, soma = 0, media = 0, variancia = 0;
    char sexovet[20], idavet[20], gender;
    float altvet[20];

    printf("====Formulario====\n");

    do{
        printf("Informe sua idade, altura e sexo(M/F) separando por espaco: ");
        scanf("%d %f %c", &idade, &altura, &gender);

        fflush(stdin);

        idavet[contador] = idade;
        altvet[contador] = altura;
        sexovet[contador] = gender;
        contador++;

        printf("\n=========================\nTem mais fichas?\n-> 1 sim\n-> 0 nao\n ---> ");
        scanf("%d", &resultado);
    }while(resultado == 1);

    for (int i = 0; i < contador ; i++){
        if ((sexovet[i] == 'f'|| sexovet[i] == 'F') && (idavet[i] >= 20 && idavet[i] <= 35)){
            mulher++;
        }
         if ((sexovet[i] == 'm'|| sexovet[i] == 'M') && altvet[i] > 1.8){
            homem++;
        }
        soma = soma + altvet[i];        //SOMA USADA PARA CALCULAR A MÉDIA
    }

    media = soma / contador;            //MÉDIA USADA PARA CALCULAR A VARIÂNCIA

    for (int i = 0; i < contador ; i++){
        float variansoma = pow((altvet[i] - media), 2);
        variancia = (variancia + variansoma) / contador;
    }

    printf("Mulheres entre 20 e 35 anos: %d\n", mulher);
    printf("Homens maior(es) que 1.80: %d\n", homem);
    printf("Variancia da altura: %f", variancia);

    return 0;
}
