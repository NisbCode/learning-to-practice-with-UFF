/*
5. Fa�a um programa que, dados duas matrizes, chame fun��es para retornar:
a) a soma destas duas matrizes
b) a soma das diagonais de cada matriz (atualize os par�metros passados por refer�ncia)
c) a multiplica��o das duas matrizes
*/

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int **allocMatriz(int m, int n){                /* FUN��O QUE USAREI PARA ALOCAR DINAMICAMENTE AS MATRIZES */

    int **a;
    int i;

    a = (int **) malloc(m*sizeof(int *));

    if (a==NULL) exit(1);
        for (i=0;i<m;i++) {
            a[i]= (int*) malloc(n*sizeof(int));
            if (a[i]==NULL) exit(1);
        }
    return a;
}



int somaMatriz(int **a, int **b, int **final, int m, int n){    /* FUN��O QUE USAREI PARA SOMAR OS VALORES NAS MATRIZES */
    int i,j;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            final[i][j] = a[i][j] + b[i][j];        //Passando por cada casa e somando seus valores para uma terceira matriz
    }
    return final;
}



void somaDiagonalMatriz(int **a, int **b, int m, int n){    /* FUN��O QUE USAREI PARA SOMAR A DIAGONAR DE CADA MATRIZ */
    int i, j = 0, somaA = 0, somaB = 0;     //Criando vari�veis auxiliares e as que conteram a soma final
    int ** diagA = allocMatriz(4, 4);
    int ** diagB = allocMatriz(4, 4);

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if(i == j){
                diagA[i][j] = a[i][j];      //Em cada diagonal receba o valor bruto. Usaremos isso apenas para evidenciar a diagonal que somaremos e verificarmos melhor
                somaA += a[i][j];           //Aqui de fato estamos somando cada valor e colocando na vari�vel
            } else{
                diagA[i][j] = 0;            //Mas se n�o for uma diagonal, substituirei por 0, assim fica mais vi�vel o que queremos somar
            }
        }
    }
    showMatriz("Diagonal da Primeira Matriz:\n", diagA, 4, 4);  //Chamando a fun��o para mostrar o que tivemos. Onde tiver 0, apenas n�o nos � relevante, j� que queremos apenas a diagonal
    printf("\tA soma eh: %d \n\n", somaA);                      //Imprimindo a soma total das diagonais

    /* O MESMO DE CIMA OCORRE AQUI, POR�M, PARA A SEGUNDA MATRIZ */
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if(i == j){
                diagB[i][j] = b[i][j];
                somaB += b[i][j];
            } else{
                diagB[i][j] = 0;
            }
        }
    }
    showMatriz("Diagonal da Segunda Matriz:\n", diagB, 4, 4);
    printf("\tA soma eh: %d \n\n\n", somaB);

    return;
}


int multiplicacaoMatriz(int **a, int **b, int **final, int m, int n){   /* FUN��O PARA MULTIPLICAR OS VALORES DAS MATRIZES */
    int i,j;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            final[i][j] = a[i][j] * b[i][j];        //O mesmo da fun��o de soma, por�m, com sinal de multiplicar. Passaremos por cada casa das matrizes e somaremos elas para pormos numa terceira matriz
    }
    return final;
}



void showMatriz(char * title, int **a, int m, int n){   /* FUN��O QUE USAREI PARA MOSTRAR AS MATRIZES */
    int i,j;

    printf("%s ",title);

    for (i=0;i<m;i++){
        for (j=0;j<n;j++)
            printf("%d \t", a[i][j]);       //Para mostrar, a premissa � simples, passaremos por cada casa da fun��o dada e imprimiremos com a formata��o colocada
        printf("\n ");
    }

    printf("\n");
}



int main( ){
    srand(time(NULL));                  //Setando um tempo para que eu possa aleatorizar os valores para as matrizes
    /* ALOCANDO CADA MATRIZ */
    int ** ab = allocMatriz(4, 4);
    int ** cd = allocMatriz(4, 4);
    int ** somaMat = allocMatriz(4, 4);
    int ** multiplicMat = allocMatriz(4, 4);
    int i,j;    //Vari�veis auxiliares

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            ab[i][j]= (rand() % 99) + 1;        //Aleatorizando cada valor das matrizes
            cd[i][j]= (rand() % 99) + 1;        //Aleatorizando cada valor das matrizes
        }
    }

    /* MOSTRANDO OS VALORES DAS MATRIZES PARA PODERMOS CONFERIR FUTURAMENTE */
    showMatriz("Matriz 1:\n", ab, 4, 4);
    showMatriz("Matriz 2:\n", cd, 4, 4);

    somaMatriz(ab, cd, somaMat, 4, 4);                  //Chamando a fun��o de soma
    showMatriz("Soma dos valores:\n", somaMat, 4, 4);   //Mostrando os valores da fun��o de soma chamando a fun��o de mostrar

    somaDiagonalMatriz(ab, cd, 4, 4);                   //Somando as diagonais e mostrando elas

    multiplicacaoMatriz(ab, cd, multiplicMat, 4, 4);                    //Chamando a func��o de multiplica��o
    showMatriz("Multiplicacao dos valores:\n", multiplicMat, 4, 4);     //Mostrando a fun��o


    return 0;
}
