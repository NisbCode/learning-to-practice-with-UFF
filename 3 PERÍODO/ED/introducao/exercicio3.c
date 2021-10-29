#include <stdio.h>
#include <stdlib.h>
#include <tuple>
#include <string.h>

auto exercicio3(const char *entrada)
{
	int n, count;
	float v = 0, soma = 0, media = 0, max = 0, min = 0;

	sscanf(entrada, "%d%n", &n, &count);
	entrada += count;
	sscanf(entrada, "%f%n", &min, &count);
	printf(" %d ", n);
	while (n--)
	{
		sscanf(entrada, "%f%n", &v, &count);
		printf(" %f", v);
		entrada += count;

		soma += v;
		if (max < v)
		{
			max = v;
		}
		if (min > v)
		{
			min = v;
		}
	}
	media = soma / count;
	auto t1 = std::make_tuple(soma, media, max, min);

	printf("\n--------Resultado--------\n");
	printf("soma: %f \n", soma);
	printf("media: %f \n", media);
	printf("max: %f \n", max);
	printf("min: %f \n", min);
	return t1;
}

int main() {

	exercicio3("2 1.0 -1.0");

	return 0;
}
