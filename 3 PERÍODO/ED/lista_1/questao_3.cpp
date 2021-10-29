/*
3. Reescreva as operações de Fila utilizando duas Pilhas como estrutura de
dados auxiliar para guardar os elementos. Manipule as pilhas por suas
interfaces padrão.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

struct PilhaBacana
{

    int topo;
    int capac;
    float *pElem;
};

void criarPilha(PilhaBacana *p)     // O(1)
{

    p->topo = -1;
    p->capac = MAX;
    p->pElem = (float *)malloc(MAX * sizeof(float));
}

int estaVazia(PilhaBacana *p)       // O(1)
{

    if (p->topo == -1)
        return 1;       // Vazia

    else
        return 0;
}

int estaCheia(PilhaBacana *p)       // O(1)
{
    if (p->topo == p->capac - 1)
        return 1;       // Cheia

    else
        return 0;
}

void empilhar(PilhaBacana *p, float v)  // O(1) DETALHE: Usei empilhar porque uso pilhas mas ela imita enfileirar conforme o inverter
{
    p->topo++;
    p->pElem[p->topo] = v;
}

float desempilhar(PilhaBacana *p)       // O(p->topo)   DETALHE: Usei desempilhar porque uso pilhas mas ela imita desenfileirar
{
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}


float retornaTopo(PilhaBacana *p)
{
    return p->pElem[p->topo];
}

void exibir(PilhaBacana *p)         // O(p->topo)
{
    printf("Pilha: [ ");
    for (int i = 0; i < (p->topo+1); i++)
    {
        printf("%.1f", p->pElem[i]);
        printf(" ");
    }
    printf("]\n");
}

float invertendoPilha(PilhaBacana *p, PilhaBacana *pa)      // Irei inverter apenas nas funções onde é necessário o início
{
    float valorTeste;
    
    while (estaVazia((PilhaBacana*)p) == 0){
        valorTeste = desempilhar(p);
        empilhar(pa, valorTeste);
    }
}



int main()  //O(N) Levando em conta que essa parte do código pode rodar infinitamente desde que o usuário continue o executando
{
    struct PilhaBacana pilhaBacana;
    struct PilhaBacana pilhaDeApoio;
    int op;
    float valor = 0;

    criarPilha(&pilhaBacana);
    criarPilha(&pilhaDeApoio);

    while (1)
    {

        printf("\n1- Empilhar/Emfileirar \n");
        printf("2- Desempilhar/Desenfileirar \n");
        printf("3- Mostrar topo/inicio \n");
        printf("4- Mostrar \n");
        printf("5- Sair \n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if (estaCheia(&pilhaBacana) == 1)
                printf("\nNao foi possivel inserir um novo elemento, pilha/fila cheia \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);

                empilhar(&pilhaBacana, valor);
            }
            break;

        case 2:
            if (estaVazia(&pilhaBacana) == 1)
                printf("\n Pilha/fila se encontra vazia \n");

            else
            {
                invertendoPilha(&pilhaBacana, &pilhaDeApoio);           // Inverto para ver o início
                valor = desempilhar(&pilhaDeApoio);
                invertendoPilha(&pilhaDeApoio, &pilhaBacana);           // Ponho ao normal
                printf("\n%.1f foi desempilhado/desenfileirado com sucesso\n", valor);
            }
            break;
        case 3:
            if (estaVazia(&pilhaBacana) == 1)
                printf("\n Pilha/fila se encontra vazia \n");

            else
            {
                invertendoPilha(&pilhaBacana, &pilhaDeApoio);
                valor = retornaTopo(&pilhaDeApoio);
                invertendoPilha(&pilhaDeApoio, &pilhaBacana);
                printf("\n Topo: %.1f \n", valor);
            }
            break;
        case 4:
            exibir(&pilhaBacana);
            break;

        case 5:
            exit(0);

        default:
            printf("\nOpcao Invalida \n");
        }
    }
}





/*
Um MIN-heap possui o significado de que os valores de todos os nós são maiores do que de seus respectivos pais.

V1: 10 						                                1º.
V2: 10  | 30 						                        2º.
V3: 10  | 30    | 8 					                    2º.
V4: 8*  | 30    | 10* 					                    2º.
V5: 8   | 30    | 10    | 31 				                3º.
V6: 8   | 30    | 10    | 31    | 28 				        3º.
V7: 8   | 28*   | 10    | 31    | 30* 				        3º.
V8: 8   | 28    | 10    | 31    | 30 | 7 			        3º.
V9: 8   | 28    | 7*    | 31    | 30 | 10* 			        3º.
V10: 7* | 28    | 8*    | 31    | 30 | 10 			        3º.
V11: 7  | 28    | 8     | 31    | 30 | 10 | 5 			    3º.
V12: 7  | 28    | 5*    | 31    | 30 | 10 | 8* 			    3º.
V13: 5* | 28    | 7*    | 31    | 30 | 10 | 8 			    3º.
V14: 5  | 28    | 7     | 31    | 30 | 10 | 8 | 29 		    4º.
V15: 5  | 28    | 7     | 29*   | 30 | 10 | 8 |31* 		    4º.
V16: 5  | 28    | 7     | 29    | 30 | 10 | 8 |31 | 2 		4º.
V17: 5  | 28    | 7     | 2*    | 30 | 10 | 8 |31 | 29* 	4º.
V18: 5  | 2*    | 7     | 28*   | 30 | 10 | 8 |31 | 29 		4º.
V19: 2* | 5*    | 7     | 28    | 30 | 10 | 8 |31 | 29		4º.

Possui nível 4.