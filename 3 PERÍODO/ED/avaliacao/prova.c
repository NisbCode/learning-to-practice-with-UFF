#include <stdio.h>
#include <stdlib.h>
#define true  1
#define false 0

typedef unsigned char bool;
typedef struct{
	int numero;
}elemen;
typedef struct no no_;
struct no{
	no_ *esquer;
	elemen dados;
	no_ *direit;
};
typedef no_* arv;


int   texto               	(void);
no_ *noC             		(void);
bool  vazia            		(no_ *no);
int   comp           		(elemen item1, elemen item2);
no_ *buscaPai        		(arv raiz, elemen dados, no_ **pai);
bool  inserir            	(arv *raiz, elemen item);
bool  remover            	(arv *raiz, elemen item);
void  esvaziar           	(arv *raiz);
void  inOrdemE      		(arv raiz);


int main(int argc, char *argv[])
{
	int opcao = 0;
	elemen dados;
	arv raiz = NULL;

    dados.numero = 6;
    inserir(&raiz, dados);
    dados.numero = 4;
    inserir(&raiz, dados);
    dados.numero = 7;
    inserir(&raiz, dados);
    dados.numero = 1;
    inserir(&raiz, dados);
    dados.numero = 5;
    inserir(&raiz, dados);
    dados.numero = 8;
    inserir(&raiz, dados);
    dados.numero = 9;
    inserir(&raiz, dados);

    printf("\n\n:In Ordem:\n\n");
    inOrdemE(raiz);

	do
	{
		opcao = texto();

		system("cls");
		switch(opcao)
		{
			case 1:
			{
				printf(":Inserindo:\n\n");

				dados.numero = 6;
                inserir(&raiz, dados);
                dados.numero = 4;
                inserir(&raiz, dados);
                dados.numero = 7;
                inserir(&raiz, dados);
                dados.numero = 1;
                inserir(&raiz, dados);
                dados.numero = 5;
                inserir(&raiz, dados);
                dados.numero = 8;
                inserir(&raiz, dados);

                dados.numero = 9;
                inserir(&raiz, dados);
				break;
			}
			case 2:
			{
				printf("Qual numeroero deseja retirar? ");
				scanf("%d", &dados.numero);

				if(remover(&raiz, dados))
					printf("\n\nExecutado com exito\n\n");
				else
					printf("\n\nNao executado\n\n");
				break;
			}
			break;
			
			case 4:
			{
				esvaziar(&raiz);
				printf("\n\nEsvaziada\n\n");
				system("pause");
				break;
			}
			case 5:
			{
				printf("\n\n:In Ordem:\n\n");
				inOrdemE(raiz);
				break;
			}
			case 0:
			{
				break;
			}
		}
	}while(opcao != 0);

	return 0;
}

int texto(void)
{
	int opcao = 0;
	
	system("cls");
	fflush(stdin);

	if((opcao < 0) || (opcao > 5))
		opcao = texto();

	return opcao;
}

no_ *noC(void)
{
	no_ *new = NULL;

	new = (no_ *) malloc (sizeof(no_));
	if(new != NULL)
	{
		new->esquer = new->direit = NULL;
		new->dados.numero = 0;
	}

	return new;
}

bool vazia(no_ *no)
{
	bool resultado = true;

	if(no == NULL)
		resultado = false;

	return resultado;
}

int comp(elemen item1, elemen item2)
{
	int resultado = 0;

	if(item1.numero > item2.numero)
		resultado = 1;
	else if(item1.numero < item2.numero)
		resultado = -1;

	return resultado;
}



no_ *buscaPai(arv raiz, elemen dados, no_ **pai)
{
	no_ *no = NULL;

	if(raiz == NULL)
		*pai = NULL;
	else
	{
		if(comp(raiz->dados, dados) == 0)
			no = raiz;
		else
		{
			*pai = raiz;

			if(comp(raiz->dados, dados) > 0)
				no = buscaPai(raiz->esquer, dados, pai);
			else
				no = buscaPai(raiz->direit, dados, pai);
		}
	}
	return no;
}

bool inserir(arv *raiz, elemen item)
{
	bool resultado = false;

	if(*raiz == NULL)
	{
		*raiz = noC();

		if(*raiz != NULL)
		{
			(*raiz)->dados = item;
			resultado = true;
		}
	}
	else
	{
		if(comp((*raiz)->dados, item) > 0)
			resultado = inserir(&((*raiz)->esquer), item);
		else if(comp((*raiz)->dados, item) < 0)
			resultado = inserir(&((*raiz)->direit), item);
	}
	return resultado;
}

bool remover(arv *raiz, elemen item)
{
	bool resultado = false;
	no_ *no, *pai, *sub, *paiSuc, *suc;
	no = pai = sub = paiSuc = suc = NULL;
	no = buscaPai(*raiz, item, &pai);
	if(no != NULL)
	{
		if(no->esquer == NULL)
			sub = no->direit;
		else
		{
			if(no->direit == NULL)
				sub = no->esquer;
			else
			{
				paiSuc = no;
				sub = no->direit;
				suc = sub->esquer;

				while(suc != NULL)
				{
					paiSuc = sub;
					sub = suc;
					suc = sub->esquer;
				}

				if(paiSuc != no)
				{
					paiSuc->esquer = sub->direit;
					sub->direit = no->direit;
				}

				sub->esquer = no->esquer;
			}
		}

		if(pai == NULL)
			*raiz = sub;
		else
		{
			if(no == pai->esquer)
				pai->esquer = sub;
			else
				pai->direit = sub;

			free(no);
			resultado = true;
		}

	}

	return resultado;
}

void esvaziar(arv *raiz)
{
	if(*raiz != NULL)
	{
		esvaziar(&(*raiz)->esquer);
		esvaziar(&(*raiz)->direit);
		free(*raiz);
		*raiz = NULL;
	}
}

void inOrdemE(arv raiz)
{
	if(raiz != NULL)
	{
		inOrdemE(raiz->esquer);
		printf("%d ", raiz->dados.numero);
		inOrdemE(raiz->direit);
	}
}