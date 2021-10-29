/*
4. Escreva um algoritmo que dada uma pilha P, inverta a ordem dos
elementos de P. Seu algoritmo deve usar espaço auxiliar constante
(somente variáveis locais e nenhum vetor extra) e:

b) duas pilhas

Seu algoritmo deve manipular as pilhas e filas por suas interfaces padrão
(somente métodos do TAD).
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

void criarPilha(PilhaBacana *p)
{

    p->topo = -1;
    p->capac = MAX;
    p->pElem = (float *)malloc(MAX * sizeof(float));
}



int estaVazia(PilhaBacana *p)
{

    if (p->topo == -1)
        return 1;

    else
        return 0;
}

int estaCheia(PilhaBacana *p)
{
    if (p->topo == p->capac - 1)
        return 1;

    else
        return 0;
}

void empilhar(PilhaBacana *p, float v)
{
    p->topo++;
    p->pElem[p->topo] = v;
}

float desempilhar(PilhaBacana *p)
{
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}


float retornaTopo(PilhaBacana *p)
{
    return p->pElem[p->topo];
}

void exibir(PilhaBacana *p)
{
    printf("Pilha: [ ");
    for (int i = 0; i < (p->topo+1); i++)
    {
        printf("%.1f", p->pElem[i]);
        printf(" ");
    }
    printf("]\n");
}

float invertendoPilha(PilhaBacana *p, PilhaBacana *pa, PilhaBacana *pas)
{
    float valorTeste;
    
    while (estaVazia((PilhaBacana*)p) == 0){            // De normal vira invertido
        valorTeste = desempilhar(p);
        empilhar(pa, valorTeste);
    }
    while (estaVazia((PilhaBacana*)pa) == 0){           // De invertido normal
        valorTeste = desempilhar(pa);
        empilhar(pas, valorTeste);
    }
    while (estaVazia((PilhaBacana*)pas) == 0){          // De normal invertido para a pilha original
        valorTeste = desempilhar(pas);
        empilhar(p, valorTeste);
    }
}



int main()
{
    struct PilhaBacana pilhaBacana;
    struct PilhaBacana pilhaDeApoio;
    struct PilhaBacana pilhaDeApoioSegunda;
    int op;
    float valor = 0;

    criarPilha(&pilhaBacana);
    criarPilha(&pilhaDeApoio);
    criarPilha(&pilhaDeApoioSegunda);

    while (1)
    {

        printf("\n1- Empilhar \n");
        printf("2- Desempilhar \n");
        printf("3- Mostrar o topo \n");
        printf("4- Inverter valores \n");
        printf("5- Mostrar \n");
        printf("6- Sair \n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if (estaCheia(&pilhaBacana) == 1)
                printf("\nNao foi possivel inserir um novo elemento, pilha cheia \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);

                empilhar(&pilhaBacana, valor);
            }
            break;

        case 2:
            if (estaVazia(&pilhaBacana) == 1)
                printf("\n Pilha se encontra vazia \n");

            else
            {
                valor = desempilhar(&pilhaBacana);
                printf("\n%.1f foi desempilhado com sucesso\n", valor);
            }
            break;

        case 3:
            if (estaVazia(&pilhaBacana) == 1)
                printf("\n Pilha se encontra vazia \n");
            else
            {
                valor = retornaTopo(&pilhaBacana);
                printf("\nTopo: %.1f\n", valor);
            }
            break;

        case 4: // Função pedida
            printf("\nPilha atual\n");
            exibir(&pilhaBacana);
            printf("\nInvertendo pilha...\n");
            invertendoPilha(&pilhaBacana, &pilhaDeApoio, &pilhaDeApoioSegunda);
            printf("\nAguarde. . .\n");
            printf("\nPilha invertida\n");
            exibir(&pilhaBacana);
            break;

        case 5:
            exibir(&pilhaBacana);
            break;

        case 6:
            exit(0);

        default:
            printf("\nOpcao Invalida \n");
        }
    }
}