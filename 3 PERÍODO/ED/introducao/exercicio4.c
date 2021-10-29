#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exercicio4(const char* entrada) {
    char nome[50], aluno_char;
    float nota;
    int n, count, aluno, i = 0;
    int tam = strlen(entrada);
    aluno_char = entrada[tam-1];
    printf("%c\n\n\n", aluno_char);
    aluno = aluno_char - '0';
    printf("%d\n\n\n", aluno);

	sscanf(entrada, "%d%n", &n, &count);
	entrada += count;
	printf(" %d ", n);

	while (n--) {
	    i++;
		sscanf(entrada, "%f%n", &nota, &count);
		//printf(" %f", nota);
		entrada += count;
		sscanf(entrada, "%s%n", &nome, &count);
		//printf(" %s", nome);
		entrada += count;
		if(i == aluno){
		if(nota >= 6){
		    printf("O aluno %s passou com %f", nome, nota);
		    return 1;
		} else {
		    printf("O aluno %s reprovou com %f", nome, nota);
		    return 0;
		}
		}
    }

}


int main() {

	exercicio4("2\n"
                       "3.0 A\n"
                       "9.0 B\n"
                       "1");

	return 0;
}
