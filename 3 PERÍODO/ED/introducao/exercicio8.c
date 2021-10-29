#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tuple>

auto exercicio8(const char* entrada) {
    int primeiro, segundo;
    int *a, *b;
    int n, count;

		sscanf(entrada, "%d%n", &primeiro, &count);
		entrada += count;
		printf(" %d ", primeiro);
		sscanf(entrada, "%d%n", &segundo, &count);
		entrada += count;
		printf(" %d ", segundo);


    int aux;
    aux = *a;
    *a  = *b;
    *b  = aux;

    return std::make_tuple(primeiro, segundo);
}


int main() {

	exercicio8("10 20");
	return 0;
}
