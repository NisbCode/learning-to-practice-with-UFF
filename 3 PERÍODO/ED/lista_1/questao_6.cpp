/*
6. Criar uma variação de pilha, chamada de PilhaMin, que, além de fornecer
as operações de pilha em tempo constante, define a operação
função obterMinimo(ref P: PilhaMin): <TElem>
que retorna o elemento de P com a menor chave em tempo constante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

struct PilhaMin
{

    int topo; 
    int capac;
    float *pElem;
};

void criarPilha(PilhaMin *p)
{

    p->topo = -1;
    p->capac = MAX;
    p->pElem = (float *)malloc(MAX * sizeof(float));
}
int estaVazia(PilhaMin *p)
{

    if (p->topo == -1)
        return 1;

    else
        return 0;
}

int estaCheia(PilhaMin *p)
{
    if (p->topo == p->capac - 1)
        return 1;

    else
        return 0;
}

void empilhar(PilhaMin *p, float v)
{
    p->topo++;
    p->pElem[p->topo] = v;
}

float desempilhar(PilhaMin *p)
{
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}

float retornaTopo(PilhaMin *p)
{
    return p->pElem[p->topo];
}
void exibir(PilhaMin *p)
{
    printf("Pilha: [ ");
    for (int i = 0; i < (p->topo+1); i++)
    {
        printf("%.1f", p->pElem[i]);
        printf(" ");
    }
    printf("]\n");
}
float obterMinimo(PilhaMin *p)
{
    float menor = 0;
    for (int i = 0; i < (p->topo+1); i++)           // Vai sempre percorrer a Pilha em busca do menor valor
    {
        if(i == 0)                                  // Como estamos falando de pilha, posso começar do 0, na fila não
            menor = p->pElem[i];                    // Ele precisa começar a comparar de algum valor inicial
        else if(i > 0 && menor > p->pElem[i])
            menor = p->pElem[i];                    // Quando achar, a põe em uma variável temporária
    }
    return menor;                                   // E retorna o valor
}










int main()
{
    struct PilhaMin pilhaMin;
    int op, i = 0;
    float valor = 0, menor = 0;

    criarPilha(&pilhaMin);

    while (1)
    {

        printf("\n1- Empilhar \n");
        printf("2- Desempilhar \n");
        printf("3- Mostrar o topo \n");
        printf("4- Mostrar o menor valor \n");
        printf("5- Mostrar \n");
        printf("6- Sair \n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            if (estaCheia(&pilhaMin) == 1)
                printf("\nNao foi possivel inserir um novo elemento, pilha cheia \n");

            else
            {
                printf("\nInsira um valor: ");
                scanf("%f", &valor);
                obterMinimo(&pilhaMin);

                empilhar(&pilhaMin, valor);
                i += 1;
            }
            break;

        case 2:
            if (estaVazia(&pilhaMin) == 1)
                printf("\n Pilha se encontra vazia \n");

            else
            {
                valor = desempilhar(&pilhaMin);
                printf("\n%.1f foi desempilhado com sucesso\n", valor);
            }
            break;

        case 3:
            if (estaVazia(&pilhaMin) == 1)
                printf("\n Pilha se encontra vazia \n");
            else
            {
                valor = retornaTopo(&pilhaMin);
                printf("\nTopo: %.1f\n", valor);
            }
            break;

        case 4: // Função pedida
            menor = obterMinimo(&pilhaMin);
            printf("\nMenor valor: %.1f\n", menor);
            break;
        case 5:
            exibir(&pilhaMin);
            break;

        case 6:
            exit(0);

        default:
            printf("\nOpcao Invalida \n");
        }
    }
}