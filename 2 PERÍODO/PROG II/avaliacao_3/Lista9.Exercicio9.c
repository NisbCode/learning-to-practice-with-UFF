/*
9. Faça a função main para funcionar com a função ordena.
void ordena (ALUNO turma[], int tam) {
int i, foraOrdem , jaOrdenados = 0;
ALUNO temp;
do {
foraOrdem = 0;
for (i = 0; i < 4 - 1 - jaOrdenados ; i++) {
if (turma[i]. media > turma[i+1]. media) {
temp = turma[i];
turma[i] = turma[i+1];
turma[i+1] = temp ;
foraOrdem = 1;
}
}
jaOrdenados ++;
} while ( foraOrdem );
}
*/

#include <stdio.h>
#define TAM 10

typedef struct aluno {
    float media;
} ALUNO;

void ordena(ALUNO turma[], int tam) {
    int i, foraOrdem, jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < 4 - 1 - jaOrdenados; i++) {
            if (turma[i].media > turma[i + 1].media) {
                temp = turma[i];
                turma[i] = turma[i + 1];
                turma[i + 1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados++;
    } while (foraOrdem);

//    printf("\nElementos do array em ordem crescente:\n");
//    for (i = 0; i < TAM; i++)
//        printf("%.2f  ", turma[i].media);
}


int main(void) {
    ALUNO alunos[TAM];

    for (int i = 0; i < TAM; i++) {
        alunos[i].media = 0.0;
    }

    for (int i = 0; i < TAM; i++) {
        printf("Insira a media do aluno %d: \n", i + 1);
        scanf("%f", &alunos[i].media);

    }

    ordena(alunos, TAM);

    return 0;
}
