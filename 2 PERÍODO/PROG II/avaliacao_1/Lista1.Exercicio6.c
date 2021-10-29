/*
6. Implemente uma fun��o que calcule as ra�zes de uma equa��o do segundo grau, do
tipo ax2 + bx + c = 0. Observa��o: para o c�lculo da raiz quadrada de um n�mero, utilize
a fun��o sqrt. Consulte a documenta��o de como us�-la no programa.
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


/* fun��o para calcular m�dia de provas */
void raizesDaEquacao(int a, int b, int c){
        float delta = (pow(b, 2)) -4.0 * a * c;

        printf("Delta = %.2f \n", delta);

        float raiz1 = (-b + sqrt(delta)) / (2 * a);
        printf("x1 (Raiz 1) = %.2f\n", raiz1);

        float raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("x2 (Raiz 2) = %.2f", raiz2);
}
