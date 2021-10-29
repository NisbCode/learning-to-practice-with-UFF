/*
14. Um cinema que possui capacidade de 100 lugares está quase sempre lotado. Certo dia cada
espectador respondeu a um questionário, onde constava:
- sua idade;
- sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
Elabore um programa que, recebendo estes dados calcule em funções e mostre:
a. a quantidade de respostas ótimo;
b. a diferença percentual entre respostas bom e regular;
c. a média de idade das pessoas que responderam ruim;
d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu
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

    /* ÓTIMOS */
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

    /* MÉDIA IDADES */
    for (int z = 0; z <= 20; z++){
        if (opcoes[z] == 4){
           ruim += idade[z];
           cont++;
        }
    }
    ruim = ruim / cont;
    printf("Media de idades ruins: %d\n", ruim);

    /* PORCENTAGEM PÉSSIMO E IDADE MAIS ALTA */
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
