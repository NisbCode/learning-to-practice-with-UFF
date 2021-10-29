/*
4. Fazer uma função denominada divs() que:
a. recebe como parâmetro um número inteiro n por valor e dois números inteiros max e min por
referência;
b. retorna 0 se o número num é primo e 1 caso contrário. Se o número não for primo, as variáveis
max e min devem assumir os valores do menor e do maior divisores inteiros do número,
respectivamente, desconsiderando o número 1 e o próprio número num.
*/

#include <stdio.h>

int divs(int num, int *min, int *max);

int main(){

    int numero = 0, minimo = 0, maximo = 0;

    printf("Digite um valor: ");
    scanf("%d", &numero);

    divs(numero, &minimo, &maximo);
    if(maximo != 0){  //Verificando que o return não deu nulo para que o valor não seja primo
        printf("\n\n==========================================\nO valor minimo divisivel para o numero %d eh %d\nE o maximo eh %d", numero, minimo, maximo);
    }else{
        printf("\n\n==========================================\nEh primo!");
    }

    return 0;
}




int divs(int num, int *min, int *max){

    int resto, cont = 0, i = 2;

    /* VERIFICANDO SE EH PRIMO */
    for (int i= 1; i <= num; i++){
        if (num % i == 0){
            cont++;
        }
    }
    if (cont == 2){
        return 0;
    }
    else if(num == 1 || num == 0){
        printf("Nao foi possivel calcular o max e min pois 0 ou 1 nao sao numeros validos aqui e tabem nao sao primos!");
    }

    if(cont != 0){     //Ou seja, se não for primo
        /* MENOR DIVISOR DO NUMERO */
        while(*min == 0){
            resto = num % i;
            if(resto == 0){
                *min = i;
            }
            i++;
        }
        /* MAIOR DIVISOR DO NUMERO */
        i = num-1;
        while(*max == 0){
            resto = num % i;
            if(resto == 0){
                *max = i;
            }
            i--;
        }
        return 1;
    }
}
