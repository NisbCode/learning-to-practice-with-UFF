/*
1. Um deque geral deve prover as seguintes operações:
procedimento insereInicio(ref D: Deque, x: <TElem>)
procedimento insereFim(ref D: Deque, x: <TElem>)
função removeInicio(ref D: Deque): <TElem>
função removeFim(ref D: Deque): <TElem>
função buscaInicio(ref D: Deque): <TElem>
função buscaFim(ref D: Deque): <TElem>
Defina o estrutura Deque e escreva os procedimentos e funções acima
de forma análoga ao realizado com Pilhas e Filas. Considere o uso da
alocação tanto sequencial quanto encadeada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

struct Deque
{
    int topo;
    int inicio;
    int capac;
    float *dElem;
};

void criarDeque(Deque *d)
{
    d->topo = -1;
    d->inicio = 0;
    d->capac = MAX;
    d->dElem = (float *)malloc(MAX * sizeof(float));
}

int vaziaD(Deque *d)
{
    if ((d->topo + 1) == d->inicio)
        return 1;                               // Deque vazio
    else
        return 0;                               // Deque não vazio
}
int cheiaD(Deque *d)
{
    if (d->topo == d->capac - 1)
        return 1;                               // Deque cheio
    else
        return 0;                               // Deque não cheio
}

int insereInicio(Deque *d, float v)             // Função baseada na de inserir no fim, porém, invertido.
{
    if (!cheiaD(d))
    {
        d->inicio--;                            // Estamos falando do inicio ele precisa sair do [0] pra -i a cada adição
        d->dElem[d->inicio] = v;                // E assim adicionamos a cada -i que vier
    }
    return 0;
}
int insereFim(Deque *d, float v)
{
    if (!cheiaD(d))
    {
        d->topo++;                              // Já esse é totalmente inspirado em como as pilhas funcionam
        d->dElem[d->topo] = v;                  // Adicionando sempre ao fim
    }
    return 0;
}

float removeInicio(Deque *d)
{
    if (!vaziaD(d))
    {
        float val = d->dElem[d->inicio];
        d->inicio = (d->inicio + 1) % MAX;
        return val;
    }
    return NULL;
}
float removeFim(Deque *d)
{
    float aux = d->dElem[d->topo];
    d->topo--;
    return aux;
}

float buscaInicio(Deque *d)
{
    return d->dElem[d->inicio];
}
float buscaFim(Deque *d)
{
    return d->dElem[d->topo];
}

void exibirD(Deque *d)
{
    printf("Deque: [ ");
    int i = d->inicio;
    for (i; i < (d->topo + 1); i++)
    {
        printf("%.1f", d->dElem[i]);
        printf(" ");
    }
    printf("]\n");
}

int main()
{
    struct Deque deque;
    int op;
    float valor = 0;

    criarDeque(&deque);

    while (1)
    {
        printf("\n1- Inserir no inicio \n");
        printf("2- Inserir no fim \n");
        printf("3- Remover no inicio \n");
        printf("4- Remover no fim \n");
        printf("5- Mostrar inicio \n");
        printf("6- Mostrar fim \n");
        printf("7- Mostrar \n");
        printf("8- Sair \n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if (cheiaD(&deque) == 1)
                printf("\nNao foi possivel inserir um novo elemento, deque cheio \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);

                insereInicio(&deque, valor);
            }
            break;
        case 2:

            if (cheiaD(&deque) == 1)
                printf("\nNao foi possivel inserir um novo elemento, deque cheio \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);

                insereFim(&deque, valor);
            }
            break;

        case 3:
            if (vaziaD(&deque) == 1)
                printf("\n Deque se encontra vazio \n");

            else
            {
                valor = removeInicio(&deque);
                printf("\n%.1f foi removido com sucesso\n", valor);
            }
            break;
        case 4:
            if (vaziaD(&deque) == 1)
                printf("\n Deque se encontra vazio \n");

            else
            {
                valor = removeFim(&deque);
                printf("\n%.1f foi removido com sucesso\n", valor);
            }
            break;

        case 5:
            if (vaziaD(&deque) == 1)
                printf("\n Deque se encontra vazio \n");
            else
            {
                valor = buscaInicio(&deque);
                printf("\nInicio: %.1f\n", valor);
            }
            break;
        case 6:
            if (vaziaD(&deque) == 1)
                printf("\n Deque se encontra vazio \n");
            else
            {
                valor = buscaFim(&deque);
                printf("\nFim: %.1f\n", valor);
            }
            break;

        case 7:
            exibirD(&deque);
            break;

        case 8:
            exit(0);

        default:
            printf("\nOpcao Invalida \n");
        }
    }
}