#include <stdio.h>
#include <stdlib.h>

int exercicio5(const char* entrada) {

    int n, count, numero, temp;
    char numero_char;
	sscanf(entrada, "%c%n", &numero_char, &count);
    numero = numero_char - '0';
    printf("%d\n\n\n", numero);
    n = numero-1;
    temp = numero;

	for (n; n > 0; n--) {
	    temp = temp-1;
	    numero *= temp;
	    printf("=====%d=====\n", numero);
    }
    return numero;
}


int main() {

	exercicio5("4");

	return 0;
}
