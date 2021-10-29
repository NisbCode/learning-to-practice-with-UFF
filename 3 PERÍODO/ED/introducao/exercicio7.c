#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exercicio7(const char* entrada) {
    char jogada1, jogada2;
    int papel = 112, tesoura = 116, pedra = 100, jog1 = 0, jog2 = 0;
    int n, count, maria = 0, joao = 0;


	sscanf(entrada, "%d%n", &n, &count);
	entrada += count;
	printf(" %d ", n);

	while (n--) {
		sscanf(entrada, "%s%n", &jogada1, &count);
		printf("%c", jogada1);
		entrada += count;
		sscanf(entrada, "%s%n", &jogada2, &count);
		printf("%c", jogada2);
		entrada += count;
		jog1 = (int)jogada1;
		jog2 = (int)jogada2;
		if(jog1 == pedra  &&  jog2 == tesoura) {
		    maria++;
		}
		if(jog1 == papel && jog2 == pedra) {
		    maria++;
		}
		if(jog1 == tesoura && jog2 == papel) {
		    maria++;
		}
		if(jog2 == pedra && jog1 == tesoura) {
		    joao++;
		}
		if(jog2 == papel && jog1 == pedra) {
		    joao++;
		}
		if(jog2 == tesoura && jog1 == papel) {
		    joao++;
		}
		printf("\npedra %c \n", pedra);
		printf("\npapel %c \n", papel);
		printf("\ntesoura %c \n", tesoura);
    }
    if(maria == joao){
        printf("Empate");
        return 'X';
    }
    if(maria > joao){
        printf("Maria");
        return 'M';
    }
    if(maria < joao){
        printf("Joao");
        return 'J';
    }

}


int main() {

	exercicio7("3\n"
                       "d t\n"
                       "d t\n"
                       "d t");
	return 0;
}
