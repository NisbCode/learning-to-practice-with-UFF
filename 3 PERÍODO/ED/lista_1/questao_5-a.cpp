/*
5. Escreva um algoritmo que dada uma fila F, inverta a ordem dos elementos
de F. Seu algoritmo deve usar espaço auxiliar constante (somente variáveis
locais e nenhum vetor extra) e:
a) uma pilha

Seu algoritmo deve manipular as pilhas e filas por suas interfaces padrão (somente métodos do TAD).
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

struct FilaLegal
{
    int inicio;
    int fim;
    int capac;
    float *fElem;
};

void criarPilha(PilhaBacana *p)
{

    p->topo = -1;
    p->capac = MAX;
    p->pElem = (float *)malloc(MAX * sizeof(float));
}
void criarFila(FilaLegal *f)
{

    f->inicio = 0;
    f->fim = 0;
    f->capac = MAX;
    f->fElem = (float *)malloc(MAX * sizeof(float));
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

int cheia(FilaLegal *f)
{
    return ((f->fim + 1) % MAX == f->inicio);
}

int vazia(FilaLegal *f)
{
    return (f->inicio == f->fim);
}

void empilhar(PilhaBacana *p, float v)
{
    p->topo++;
    p->pElem[p->topo] = v;
}

int enfileirar(FilaLegal *f, float v)
{
    if (!cheia(f))
    {
        f->fElem[f->fim] = v;
        f->fim = (f->fim + 1) % MAX;

    }
    return 0;
}

float desempilhar(PilhaBacana *p)
{
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}

float desenfileirar(FilaLegal *f)
{
    if (!vazia(f))
    {
        float val = f->fElem[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return val;
    }
    return NULL;
}

float retornaTopo(PilhaBacana *p)
{
    return p->pElem[p->topo];
}
float retornaInicio(FilaLegal *f)
{
    return f->fElem[f->inicio];
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
void exibirF(FilaLegal *f)
{
    printf("Fila: [ ");
    int i = f->inicio;
    for (i; i < (f->fim); i++)
    {
        printf("%.1f", f->fElem[i]);
        printf(" ");
    }
    printf("]\n");
}
float invertendoFila(FilaLegal *f, PilhaBacana *p)      // Mesma coisa da 4-A), mas agora a Fila é a original
{
    float valorTeste;
    while (vazia(f) == 0){
        valorTeste = desenfileirar(f);
        empilhar(p, valorTeste);
            
    }
    while (estaVazia((PilhaBacana*)p) == 0){
        valorTeste = desempilhar(p);
        enfileirar(f, valorTeste);
    }
}




int main()
{
    struct PilhaBacana pilhaBacana;
    struct FilaLegal filaLegal;
    int op;
    float valor = 0;

    criarPilha(&pilhaBacana);
    criarFila(&filaLegal);

    while (1)
    {

        printf("\n1- Enfileirar \n");
        printf("2- Desenfileirar \n");
        printf("3- Inverter valores \n");
        printf("4- Mostrar inicio \n");
        printf("5- Mostrar \n");
        printf("6- Sair \n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if (cheia(&filaLegal) == 1)
                printf("\nNao foi possivel inserir um novo elemento, fila cheia \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);

                enfileirar(&filaLegal, valor);
            }
            break;

        case 2:
            if (vazia(&filaLegal) == 1)
                printf("\n Fila se encontra vazia \n");

            else
            {
                valor = desenfileirar(&filaLegal);
                printf("\n%.1f foi desenfileirado com sucesso\n", valor);
            }
            break;

        case 3: // Função pedida
            printf("\nFila atual\n");
            exibirF(&filaLegal);
            printf("\nInvertendo fila...\n");
            invertendoFila(&filaLegal, &pilhaBacana);
            printf("\nAguarde. . .\n");
            printf("\nFila invertida\n");
            exibirF(&filaLegal);
            break;

        case 4:
            if (vazia(&filaLegal) == 1)
                printf("\n Fila se encontra vazia \n");
            else
            {
                valor = retornaInicio(&filaLegal);
                printf("\nInicio: %.1f\n", valor);
            }
            break;
            
        case 5:
            exibirF(&filaLegal);
            exibir(&pilhaBacana);
            break;
            
        case 6:
            exit(0);

        default:
            printf("\nOpcao Invalida \n");
        }
    }
}