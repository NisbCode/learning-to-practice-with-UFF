#include <stdio.h>
#include <stdlib.h>
#define TAM_TABLE 19

typedef struct{
    int registration;
    char name[100];
}People;
People tableHash[TAM_TABLE];

void iniciar() {
    for(int i = 0; i < TAM_TABLE; i++)
        tableHash[i].registration = -1;
}


int espalhamento(int key) {
    return key % TAM_TABLE;
}

People pegarValoresPessoa() {
    People people;
    printf("Insira a matricula: ");
    scanf("%d", &people.registration);
    scanf("%*c");
    printf("Insira o nome: ");
    fgets(people.name, 100, stdin);
    return people;
}

void inserir() {
    People people = pegarValoresPessoa();
    int indice = espalhamento(people.registration);
    while(tableHash[indice].registration != -1) indice = espalhamento(indice + 1);
    tableHash[indice] = people;
}

People* buscar(int key) {
    int indice = espalhamento(key);
    while(tableHash[indice].registration != -1) {
        if(tableHash[indice].registration == key)
            return &tableHash[indice];
        else
            indice = espalhamento(indice + 1);
    }
    return NULL;
}

void mostrar() {
    int i;
    printf("\n\n\n\n");
    for(i = 0; i < TAM_TABLE; i++) {
        if(tableHash[i].registration != -1)
            printf("%2d = Matricula: %d => Nome: %s", i, tableHash[i].registration, tableHash[i].name);
        else
            printf("%2d =\n", i);
    }
    printf("\n\n\n\n");
}

int main() {
    int option, key;
    People *people;

    iniciar();

    do{
        printf("1 - Cadastrar um novo aluno\n");
        printf("2 - Buscar um novo aluno cadastrado\n");
        printf("3 - Mostrar todos os alunos cadastrados\n");
        printf("0 - Sair\n");
        printf("O que deseja fazer? ");
        scanf("%d", &option);

        switch(option) {
        case 0:
            printf("Finalizado\n");
            break;
        case 1:
            inserir();
            break;
        case 2:
            printf("Digite a matricula a ser buscada: ");
            scanf("%d", &key);
            people = buscar(key);

            if(people)
                printf("\n\tMatricula: %d => Nome: %s\n", people->registration, people->name);
            else
                printf("\nNao encontrada\n");
            break;
        case 3:
            mostrar();
            break;
        default:
            printf("Opcao invalida\n");
        }

    }while(option != 0);

    return 0;
}