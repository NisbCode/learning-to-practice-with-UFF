/*
14. Um cinema que possui capacidade de 100 lugares est� quase sempre lotado. Certo dia cada
espectador respondeu a um question�rio, onde constava:
- sua idade;
- sua opini�o em rela��o ao filme, que podia ser: �timo, bom, regular, ruim ou p�ssimo.
Elabore um programa que, recebendo estes dados calcule em fun��es e mostre:
a. a quantidade de respostas �timo;
b. a diferen�a percentual entre respostas bom e regular;
c. a m�dia de idade das pessoas que responderam ruim;
d. a porcentagem de respostas p�ssimo e a maior idade que utilizou esta op��o;
e. a diferen�a de idade entre a maior idade que respondeu �timo e a maior idade que respondeu
ruim.
*/

#include <stdio.h>

int main(){

    int idade[50] = {}, opcoes[50] = {}, i = 0, contador = 1, otimo = 0, bomregular = 0, ruim = 0, cont = 0, pessimo = 0, tudo = 0, maior = 0;
    float diferenca = 0;

    do{
        printf("Me diga sua idade para comecarmos: ");
        scanf("%d", &idade[i]);
        printf("Em relacao ao filme digite dua opniao sobre ele:\n1 - Foi otimo\n2 - Foi bom\n3 - Foi regular\n4 - Foi ruim\n5 - Foi pessimo\n---> ");
        scanf("%d", &opcoes[i]);
        i++;
        printf("Existem mais pessoas para a avaliacao?\n1 Sim\n0 Nao\n---> ");
        scanf("%d", &contador);

    }while(contador != 0);

    /* �TIMOS */
    for (int z = 0; z <= 20; z++){
        if (opcoes[z] == 1){
            otimo++;
        }
    }
    printf("%d pessoas responderam que o filme foi otimo\n", otimo);

    /* PORCENTAGEM BOM/REGULAR */
    for (int z = 0; z <= 20; z++){
        if (opcoes[z] == 2){
            bomregular++;
            diferenca++;
        }
        else if(opcoes[z] == 3){
            bomregular++;
        }
    }
    diferenca = bomregular - diferenca;
    diferenca = diferenca / bomregular;
    diferenca = diferenca * 100;
    printf("Diferenca entre respostas bom e regular: %.2f\n", diferenca);

    /* M�DIA IDADES */
    for (int z = 0; z <= 20; z++){
        if (opcoes[z] == 4){
           ruim += idade[z];
           cont++;
        }
    }
    ruim = ruim / cont;
    printf("Media de idades ruins: %d\n", ruim);

    /* PORCENTAGEM P�SSIMO E IDADE MAIS ALTA */
    for (int z = 0; z <= 20; z++){
        if (opcoes[z] == 5){
            pessimo++;
            if (maior < idade[z]){
                maior = idade[z];
            }
        }
        tudo++;
    }
    pessimo = (pessimo / tudo) * 100;
    printf("%d por cento das pessoas escolheram pessimo e %d eh a maior idade que votou nisso", pessimo, maior);

   return 0;
}
