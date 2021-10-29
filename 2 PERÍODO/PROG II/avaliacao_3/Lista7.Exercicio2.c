/*
2. O que ser� impresso na tela? Mostre o andamento da execu��o.


#include < stdio .h >                   //Buscar� fun��es provenientes da biblioteca stdio.h
#include < string .h >                  //Buscar� fun��es provenientes da biblioteca string.h

int main (void) {

char *frase = "Otimo teste";            //Cria��o de ponteiro chamado frase que conter� caract�res atribuidos dentre aspas duplas
char *p , misterio[80];                 //Cria��o de ponteiros chamados p e misterio, esse �ltimo conter� limite de 80 caract�res
int i = 0;                              //Cria��o de vari�vel i iniciada com valor zero
int j = 0;                              //Cria��o de vari�vel j iniciada com valor zero
p = frase + strlen ( frase ) - 1;       //O ponteiro p ser� inicializado como ultimo valor da vari�vel frase. Isso porque a fun��o "strlen", da biblioteca string.h, pegar� o tamanho da vari�vel e subtrair� 1, o levando para o �ltimo index que � a letra "e"
while (*p != � �) {                     //Enquanto n�o encontrar um caracter espa�o, fa�a:
misterio[i] = *p;                       //Vetor misterio no index i recebe valor de p
i ++; p --;                             //Vari�vel i incrementa 1 ao seu valor, vetor p diminui 1
}                                       //Ele acha um caracter espa�o e sai do loop
misterio[i] = � �; i ++;                //No index em que ele parou, ele acrescenta o espa�o a vari�vel misterio e incrementa 1 ao i
while ( frase[j] != � �) {              //Enquanto a vari�vel frase no index determinado (inicalmente 0) for diferente de espa�o, fa�a:
misterio [i] = frase[j];                //Vari�vel mist�rio no index que parou recebe frase no index determinado
j ++; i ++;                             //Vari�vel i e j incrementam 1 ao seu valor
}                                       //Ele acha um caracter espa�o e sai do loop
misterio[i] = �\0 �;                    //Recebe o caracter que significa o bot�o de Enter, pular para a pr�xima linha
puts (misterio);                        //Imprime a vari�vel misterio
return 0;
}

> Tendo explicado passo a passo, resumidamente o que o c�digo faz � inverter apenas a �ltima palavra e a p�r na frente da primeira palavra
Imprime "etset Otimo"
*/
