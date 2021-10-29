/*
5. Escreva um programa em C para ler um valor X e um valor Z (se Z for menor que X
deve ser lido um novo valor para Z). Contar quantos números inteiros devemos somar em
sequência (a partir do X inclusive) para que a soma ultrapasse a Z o mínimo possível.
Escrever o valor final da contagem.
Exemplo:
X Z Resposta
3 20 5 (3+4+5+6+7=25)
2 10 4 (2+3+4+5=14)
30 40 2 (30+31=61)
*/

#include <stdio.h>

int main(){

    int x, z, k = 0, soma = 0, resposta = 0;

    printf("Diga um valor para x: ");
    scanf("%d", &x);
    printf("Diga um valor para z: ");
    scanf("%d", &z);

    if((z < x) || (z == x)){
        while((z < x) || (z == x)){
            printf("Seriam %d numeros a mais que esse para z chegar a ser MAIOR que x. Insira um novo valor: ", ((x-z)+1));
            scanf("%d", &z);
        }
    }
    resposta = x;

    /* Preparação para imprimir o valor de resposta */
    printf("(");
    for(resposta; soma < z; resposta++){
        soma = soma + resposta;
        k = k + 1;
        if(soma < z){
            printf("%d+", resposta);
        }else{
            printf("%d=%d) %d", resposta, soma, k);
        }
    }
    return 0;
}
