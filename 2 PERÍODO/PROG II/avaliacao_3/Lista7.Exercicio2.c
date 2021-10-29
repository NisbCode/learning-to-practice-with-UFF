/*
2. O que será impresso na tela? Mostre o andamento da execução.


#include < stdio .h >                   //Buscará funções provenientes da biblioteca stdio.h
#include < string .h >                  //Buscará funções provenientes da biblioteca string.h

int main (void) {

char *frase = "Otimo teste";            //Criação de ponteiro chamado frase que conterá caractéres atribuidos dentre aspas duplas
char *p , misterio[80];                 //Criação de ponteiros chamados p e misterio, esse último conterá limite de 80 caractéres
int i = 0;                              //Criação de variável i iniciada com valor zero
int j = 0;                              //Criação de variável j iniciada com valor zero
p = frase + strlen ( frase ) - 1;       //O ponteiro p será inicializado como ultimo valor da variável frase. Isso porque a função "strlen", da biblioteca string.h, pegará o tamanho da variável e subtrairá 1, o levando para o último index que é a letra "e"
while (*p != ’ ’) {                     //Enquanto não encontrar um caracter espaço, faça:
misterio[i] = *p;                       //Vetor misterio no index i recebe valor de p
i ++; p --;                             //Variável i incrementa 1 ao seu valor, vetor p diminui 1
}                                       //Ele acha um caracter espaço e sai do loop
misterio[i] = ’ ’; i ++;                //No index em que ele parou, ele acrescenta o espaço a variável misterio e incrementa 1 ao i
while ( frase[j] != ’ ’) {              //Enquanto a variável frase no index determinado (inicalmente 0) for diferente de espaço, faça:
misterio [i] = frase[j];                //Variável mistério no index que parou recebe frase no index determinado
j ++; i ++;                             //Variável i e j incrementam 1 ao seu valor
}                                       //Ele acha um caracter espaço e sai do loop
misterio[i] = ’\0 ’;                    //Recebe o caracter que significa o botão de Enter, pular para a próxima linha
puts (misterio);                        //Imprime a variável misterio
return 0;
}

> Tendo explicado passo a passo, resumidamente o que o código faz é inverter apenas a última palavra e a pôr na frente da primeira palavra
Imprime "etset Otimo"
*/
