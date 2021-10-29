/*
2. Reescreva as operações de Pilha utilizando duas Filas como estrutura de
dados auxiliar para guardar os elementos. Manipule as filas por suas
interfaces padrão.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

struct FilaLegal
{
    int inicio;
    int fim;
    int capac;
    float *fElem;
};

void criarFila(FilaLegal *f)
{

    f->inicio = 0;
    f->fim = 0;
    f->capac = MAX;
    f->fElem = (float *)malloc(MAX * sizeof(float));
}


int cheia(FilaLegal *f)
{
    return ((f->fim + 1) % MAX == f->inicio);
}

int vazia(FilaLegal *f)
{
    return (f->inicio == f->fim);
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

float retornaInicio(FilaLegal *f)
{
    return f->fElem[f->inicio];
}

void exibirF(FilaLegal *f)
{
    printf("Fila/pilha: [ ");
    int i = f->inicio;
    for (i; i < (f->fim); i++)
    {
        printf("%.1f", f->fElem[i]);
        printf(" ");
    }
    printf("]\n");
}

float invertendoFila(FilaLegal *f, FilaLegal *fa)       // Usei o inverso das filas para representar uma pilha nas funções
{
    float valorTeste;
    int i = f->fim-1;                           //Para inverter uma fila eu vou pegar o local onde está o último valor
        for (i; i >= (f->inicio); i--){         // E percorrer até o início
            valorTeste = f->fElem[i];
            enfileirar(fa, valorTeste);
        }
        while (vazia(fa) == 0){                 //Depois devolver para a fila original
            desenfileirar(f);
            valorTeste = desenfileirar(fa);
            enfileirar(f, valorTeste);
        }
    }
    


int main()
{
    struct FilaLegal filaLegal;
    struct FilaLegal filaLegalDeApoio;
    int op;
    float valor = 0;

    criarFila(&filaLegal);
    criarFila(&filaLegalDeApoio);

    while (1)
    {

        printf("\n1- Enfileirar/Empilhar \n");
        printf("2- Desenfileirar/Desempilhar \n");
        printf("3- Mostrar inicio/Mostrar topo \n");
        printf("4- Mostrar \n");
        printf("5- Sair \n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if (cheia(&filaLegal) == 1)
                printf("\nNao foi possivel inserir um novo elemento, fila/pilha cheia \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);

                enfileirar(&filaLegal, valor);
            }
            break;

        case 2:
            if (vazia(&filaLegal) == 1)
                printf("\n Fila/pilha se encontra vazia \n");

            else
            {
                invertendoFila(&filaLegal, &filaLegalDeApoio);
                valor = desenfileirar(&filaLegal);
                invertendoFila(&filaLegal, &filaLegalDeApoio);
                printf("\n%.1f foi desenfileirado/desempilhar com sucesso\n", valor);
            }
            break;

        case 3:
            if (vazia(&filaLegal) == 1)
                printf("\n Fila/pilha se encontra vazia \n");
            else
            {
                invertendoFila(&filaLegal, &filaLegalDeApoio);
                valor = retornaInicio(&filaLegal);
                invertendoFila(&filaLegal, &filaLegalDeApoio);
                printf("\nTopo: %.1f\n", valor);
            }
            break;
            
        case 4:
            exibirF(&filaLegal);
            break;
            
        case 5:
            exit(0);

        default:
            printf("\nOpcao Invalida \n");
        }
    }
}