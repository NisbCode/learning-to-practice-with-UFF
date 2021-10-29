/*
6. Implemente uma função que calcule as raízes de uma equação do segundo grau, do
tipo ax2 + bx + c = 0. Observação: para o cálculo da raiz quadrada de um número, utilize
a função sqrt. Consulte a documentação de como usá-la no programa.
*/

#include <stdio.h>
#include <math.h>

int main (void){

    int a, b, c;

    printf("Digite o valor de a:\n");
    scanf("%d", &a);
    printf("Digite o valor de b:\n");
    scanf("%d", &b);
    printf("Digite o valor de c:\n");
    scanf("%d", &c);

    raizesDaEquacao(a, b, c);

    return 0;
}


/* função para calcular média de provas */
void raizesDaEquacao(int a, int b, int c){
        float delta = (pow(b, 2)) -4.0 * a * c;

        printf("Delta = %.2f \n", delta);

        float raiz1 = (-b + sqrt(delta)) / (2 * a);
        printf("x1 (Raiz 1) = %.2f\n", raiz1);

        float raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("x2 (Raiz 2) = %.2f", raiz2);
}
