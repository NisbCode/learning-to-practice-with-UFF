/*
6. Considere que voc� digitou o seu nome para o programa abaixo. O que ser� impresso?
Indique o que voc� digitou. Justifique sua resposta. (n�o vale ponto para apresenta��o)

#include < stdio .h >
#include < string .h >
#define MAX 50
int main (void) {
char texto[MAX +2], temp ;
int tam , i;
gets( texto );                      //Quando o programa chega nessa linha, ele pede pra que eu digite, insiri "Nathalia Ignacio"
tam = strlen ( texto );
for (i = 0; i < tam ; i ++) {
temp = texto[i];                    //A vari�vel temp recebe a letra que est� no index em quest�o, ex.: temp = texto[0] --> "N" 78 na tabela ASCII
texto[i] = texto[ tam -1 - i ];     //Recebe o ultimo valor da vari�vel no index, ex.: texto[0] = texto[18-1(do enter)-i(pra que substitua aos poucos cada linha)]
texto[strlen(texto) -1 - i] = temp ;//A �ltima letra recebe o valor guardado na vari�vel temp, dando a entender que ela � uma vari�vel auxiliar que guarda TEMPorariamente o valor
}
puts ( texto );                     //Ele retornar� meu nome normalmente, a magia est� no que ele fez com meu nome durante
return 0;
}

Resumidamente, quando i == 0:
- temp guardar� "N"                                                     Nathalia Ignacio
- texto na primeira casa ter� sua letra mudada pela �ltima              oathalia Ignacio
- texto na ultima linha receber� o valor guardado em temp               oathalia IgnaciN

quando i == 1:
- temp guardar� "a"                                                     oathalia IgnaciN
- texto na segunda casa ter� sua letra mudada pela penultima            oithalia IgnaciN
- texto na ultima linha receber� o valor guardado em temp               oithalia IgnacaN

...
No exato meio do tamanho da vari�vel "tam" (i=8), meu nome estar� totalmente ao contr�rio por substituirem igualmente valores da esquerda para a direita e vice-versa
...

quando i == 10:
- temp guardar� "l"                                                     oicangia IlahtaN
- texto na 11 casa ter� sua letra mudada pela 11 de tr�s para frente    oicangia IgahtaN
- texto na 11 linha receber� o valor guardado em temp                   oicanlia Ign�caN

quando i = 16, meu nome retornar� ao normal
Nathalia Ignacio
*/
