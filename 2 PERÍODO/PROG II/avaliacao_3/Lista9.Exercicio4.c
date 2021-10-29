/*
4. Tendo o seguinte trecho de código (compilável e executável corretamente):


a. Implemente a função atribui, conforme o seu protótipo (dica: somente 1 linha de
código no corpo da função).
b. Implemente a função get_sobrenome, conforme o seu protótipo, que retorna a última
palavra do nome.
c. O que será impresso no segundo printf?
d. O que será impresso no terceiro printf?
*/

#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define oi printf("to aqui\n");

void atribui(char **nomes, int indice, char *nome){
    nomes[indice] = nome;
}

char * get_sobrenome(char *nome){
    char *pegando_sobrenome;
    pegando_sobrenome = malloc(25 * sizeof(char));
    int z = 0;
    for (int i = strlen(nome); i >= 0; i--){
        if(nome[i] == '\0'){
            continue;
        }
        if (nome[i] == ' '){
            pegando_sobrenome[z] = '\0';
            break;
        }
        pegando_sobrenome[z] = nome[i];
        z++;
    }
    strrev(pegando_sobrenome);
    return pegando_sobrenome;
}

void main()
{
    int i;
    char **nomes;
    char *sobrenome;

    nomes = (char **) malloc(MAX*sizeof(char *));

    for ( i=0 ; i<MAX ; i++) {
        nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
    }

    atribui(nomes,0,"Fulano Silva");
    atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte");
    atribui(nomes,3,"Pedro dos Santos");


    for (i=0 ; i<MAX ; i++) {
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d",strlen(sobrenome)>5?i:0); //Tamanho do sobrenome
    }

    printf("\n%c", nomes[0][3]); //4 letra do primeiro nome
}
