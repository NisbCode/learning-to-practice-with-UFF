/*
9. Implementar a fun��o INVERTE que recebe um n�mero unsigned int como par�metro
e retorna este n�mero escrito ao contr�rio. Ex: 431 <-> 134.
*/

#include <stdio.h>

int inverte(unsigned numero);

int main(){

    unsigned numero;
    unsigned resultado;

    printf("Digite um valor a ser invertido: ");
    scanf("%d", &numero);

    resultado = inverte(numero);
    printf("%d", resultado);
}

int inverte(unsigned numero){
    if(numero < 10){
        return numero;
    }else{
        printf("%d", numero %10);
        numero = numero / 10;
        return inverte(numero);
    }
    return 0;
}
