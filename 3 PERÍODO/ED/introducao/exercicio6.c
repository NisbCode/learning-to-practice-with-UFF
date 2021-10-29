#include <stdio.h>
#include <stdlib.h>

int exercicio6(const char *entrada)
{
	int n, count, numero, fib1 = 1, fib2 = 1, soma;

	char numero_char;
	sscanf(entrada, "%c%n", &numero_char, &count);
	numero = numero_char - '0';
	printf("%d\n\n\n", numero);

	for (n = 3; n <= numero; n = n + 1)	{
		soma = fib1 + fib2;
		fib1 = fib2;
		fib2 = soma;
	}
    printf("%d\n\n\n", fib2);
	return fib2;
}

int main()
{
	exercicio6("4");

	return 0;
}
