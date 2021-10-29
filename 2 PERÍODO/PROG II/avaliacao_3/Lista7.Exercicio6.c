/*
6. Considere que você digitou o seu nome para o programa abaixo. O que será impresso?
Indique o que você digitou. Justifique sua resposta. (não vale ponto para apresentação)

#include < stdio .h >
#include < string .h >
#define MAX 50
int main (void) {
char texto[MAX +2], temp ;
int tam , i;
gets( texto );                      //Quando o programa chega nessa linha, ele pede pra que eu digite, insiri "Nathalia Ignacio"
tam = strlen ( texto );
for (i = 0; i < tam ; i ++) {
temp = texto[i];                    //A variável temp recebe a letra que está no index em questão, ex.: temp = texto[0] --> "N" 78 na tabela ASCII
texto[i] = texto[ tam -1 - i ];     //Recebe o ultimo valor da variável no index, ex.: texto[0] = texto[18-1(do enter)-i(pra que substitua aos poucos cada linha)]
texto[strlen(texto) -1 - i] = temp ;//A última letra recebe o valor guardado na variável temp, dando a entender que ela é uma variável auxiliar que guarda TEMPorariamente o valor
}
puts ( texto );                     //Ele retornará meu nome normalmente, a magia está no que ele fez com meu nome durante
return 0;
}

Resumidamente, quando i == 0:
- temp guardará "N"                                                     Nathalia Ignacio
- texto na primeira casa terá sua letra mudada pela última              oathalia Ignacio
- texto na ultima linha receberá o valor guardado em temp               oathalia IgnaciN

quando i == 1:
- temp guardará "a"                                                     oathalia IgnaciN
- texto na segunda casa terá sua letra mudada pela penultima            oithalia IgnaciN
- texto na ultima linha receberá o valor guardado em temp               oithalia IgnacaN

...
No exato meio do tamanho da variável "tam" (i=8), meu nome estará totalmente ao contrário por substituirem igualmente valores da esquerda para a direita e vice-versa
...

quando i == 10:
- temp guardará "l"                                                     oicangia IlahtaN
- texto na 11 casa terá sua letra mudada pela 11 de trás para frente    oicangia IgahtaN
- texto na 11 linha receberá o valor guardado em temp                   oicanlia IgnácaN

quando i = 16, meu nome retornará ao normal
Nathalia Ignacio
*/
