/*
10. Um cinema que possui capacidade de 20 lugares está sempre lotado. Certo dia cada
espectador respondeu a um questionário, onde constava:
- sua idade;
- sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
Elabore um programa que, recebendo estes dados calcule e mostre:
a. a quantidade de respostas ótimo;
b. a diferença percentual entre respostas bom e regular;
c. a média de idade das pessoas que responderam ruim;
d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que
respondeu ruim.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int idade[20] = {}, opcoes[20] = {}, i = 0, contador = 1, otimo = 0, bom = 0, regular = 0, ruim = 0, cont = 0, pessimo = 0, tudo = 0, maiorpessimo = 0, maiorotimo = 0, maiorruim = 0, pessoacinema = 20;
    float diferenca = 0, mediaruim = 0;

        do{
            printf("========================================\n");
            printf("Me diga sua idade para comecarmos: ");
            scanf("%d", &idade[i]);

            printf("-----------------\n");
            printf("Em relacao ao filme digite sua opniao sobre ele:\n1 - Foi otimo\n2 - Foi bom\n3 - Foi regular\n4 - Foi ruim\n5 - Foi pessimo\n---> ");
            scanf("%d", &opcoes[i]);
            i++;

            printf("-----------------\n");
            printf("Existem mais pessoas para a avaliacao?\n1 Sim\n0 Nao\n---> ");
            scanf("%d", &contador);
            pessoacinema -= 1;
            if(pessoacinema <= 0){
                printf("Todos do cinema já responderam! Estamos encerrando a pesquisa.\n\n");
                break;
            }
        }while (contador != 0);

    printf("\n\n\n======RESPOSTAS======\n");

    /* ÓTIMOS E MAIOR IDADE */
    for (int z = 0; z <= i; z++){
        if (opcoes[z] == 1){
            otimo++;
            if(maiorotimo < idade[z]){
                maiorotimo = idade[z];
            }
        }
    }
    printf("%d pessoas responderam que o filme foi otimo\n", otimo);
    
    

    /* PORCENTAGEM BOM/REGULAR */
    for (int z = 0; z <= i; z++){
        if (opcoes[z] == 2){
            bom++;
        }
        else if (opcoes[z] == 3){
            regular++;
        }
    }
    diferenca = abs(bom - regular);
    if(bom > regular){
        diferenca /= bom;
    }else{
        diferenca /= regular;
    }
    diferenca = (int) diferenca * 100;
        if((bom != 0) && (regular != 0)){
    printf("Diferenca entre respostas bom e regular: %d por cento\n", diferenca);
    }else{
        printf("Nao tivemos ambas opinioes 'bom e regular' marcadas para sabermos uma diferenca");
    }
    
    
    /* RUIM, MÉDIA IDADES E MAIOR IDADE */
    for (int z = 0; z <= i; z++){
        if (opcoes[z] == 4){
            mediaruim += idade[z];
            ruim++;
            if(maiorruim < idade[z]){
                maiorruim = idade[z];
            }
            cont++;
        }
    }
    mediaruim /= cont;
    if(ruim != 0){
        printf("Media de idades ruins: %.2f\n", mediaruim);
    }else{
        printf("Nao tivemos opnioes marcadas como ruins para fazermos a media\n");
    }
    
    

    /* PORCENTAGEM PÉSSIMO E IDADE MAIS ALTA */
    for (int z = 0; z <= i; z++){
        if(opcoes[z] == 5){
            pessimo++;
            if(maiorpessimo < idade[z]){
                maiorpessimo = idade[z];
            }
        }
    }
    int porcentpessimo = ((pessimo / i) * 100);
    if(pessimo != 0){
        printf("%d por cento das pessoas escolheram pessimo e %d eh a maior idade que votou nisso\n", porcentpessimo, maiorpessimo);
    }else{
        printf("Nao tivemos opinioes marcadas como pessimo\n");
    }
    
    
    
    /* DIFERENÇA ENTRE MAIOR IDADE RUIM E ÓTIMO */
    float diferenruimotimo = abs(maiorruim - maiorotimo);
    if((ruim != 0) && (otimo != 0)){
        printf("%.2f eh a diferenca de idade das pessoas escolheram otimo e bom", diferenruimotimo);
    }else{
        printf("Nao tivemos ambas opinioes 'otimo e bom' marcadas para sabermos uma diferenca");
    }
    
    return 0;
}