#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define MAX 300

using namespace std;                        // Essa foi a primeira questão que fiz, então ela ficou em um padrão diferente

typedef enum
{
    FALSE,
    TRUE
} BOOL;

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO a[MAX];
    int top;
} PILHA;

REGISTRO criarRegistro(TIPOCHAVE chave)
{
    REGISTRO reg;
    reg.chave = chave;
    return reg;
}

void iniciar(PILHA *pilha)
{
    pilha->top = 0;
}

int vazia(PILHA *pilha)
{
    return pilha->top == 0;
}

int cheia(PILHA *pilha)
{
    return pilha->top == MAX;
}


int empilha(REGISTRO elem, PILHA *pilha)            // Nada muito diferente, ela tem todas as funções principais
{
    if (cheia(pilha))
    {
        return false;
    }
    pilha->a[pilha->top] = elem;
    pilha->top++;
    return true;
}

int desempilha(PILHA *pilha, REGISTRO *elem)        // Com a ideia bem parecida, mas acabei achando uma forma mais eficaz
{
    if (vazia(pilha))
        return false;
    *elem = pilha->a[pilha->top - 1];
    pilha->top--;
    return true;
}

void esvaziar(PILHA *pilha)
{
    pilha->top = 0;
}

int top(PILHA *pilha, REGISTRO *elem)               // E foi a que fiz nas demais questões
{
    if (vazia(pilha))
        return false;
    *elem = pilha->a[pilha->top - 1];
    return true;
}

// O principal vem daqui para baixo, onde vemos as funções pedidas
int operando(char incognita)                        //Checando se o char é uma incógnita
{
    return (incognita >= 'A' && incognita <= 'Z') || (incognita >= 'a' && incognita <= 'z');
}


int ordemDeImportancia(char operador)     //Função que determina a ordem de importância dos operadores em uma conta, podendo assim calcular corretamente
{
    switch (operador)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    }
    return 0;
}


int inpos(char expr[])      //Função que remonta a expressão a transformando assim de infixa para posfixa
{

    PILHA pilha;
    iniciar(&pilha);

    int i, aux;
    REGISTRO elem;

    for (i = 0, aux = -1; expr[i]; ++i)
    {
        if (operando(expr[i]))
            expr[++aux] = expr[i];

        else if (expr[i] == '(')
            empilha(criarRegistro(expr[i]), &pilha);

        else if (expr[i] == ')')
        {
            while (!vazia(&pilha) && top(&pilha, &elem))
            {
                desempilha(&pilha, &elem);
                expr[++aux] = elem.chave;
            }

            if (!vazia(&pilha) && top(&pilha, &elem))
                return 0;
            else
                desempilha(&pilha, &elem);
        }

        else
        {
            while (!vazia(&pilha) && ordemDeImportancia(expr[i]) <= ordemDeImportancia(top(&pilha, &elem)))
            {
                desempilha(&pilha, &elem);
                expr[++aux] = elem.chave;
            }
            empilha(criarRegistro(expr[i]), &pilha);
        }
    }
    while (!vazia(&pilha))      //desempilha todos os elementos da pilha
    {
        desempilha(&pilha, &elem);
        expr[++aux] = elem.chave;
    }
    expr[++aux] = '\0';

    string my_str = expr;
    my_str.erase(remove(my_str.begin(), my_str.end(), '('), my_str.end()); //remove ( da string
    my_str.erase(remove(my_str.begin(), my_str.end(), ')'), my_str.end()); //remove ) da string
    cout << "Expressao na Notacao Polonesa Reversa: " << my_str;
    esvaziar(&pilha);
}

int main()
{
    char expr[60];

// Não existe um menu dessa vez já que ela usa o empilhar em sua execução e não com valores que a damos
    printf("Insira uma expressao envolvendo as 4 operacoes principais (+-*/): ");
    fgets(expr, 60, stdin);
    inpos(expr);

    return 0;
}
