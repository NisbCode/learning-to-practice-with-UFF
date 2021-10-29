#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exercicio2(const char *entrada)
{
	int n, count, um = 0, dois = 0, tres = 0;

	sscanf(entrada, "%d%n", &n, &count);
	entrada += count;

	while (n--)
	{
		int v = 0;
		sscanf(entrada, "%d%n", &v, &count);
		printf(" %d", v);
		entrada += count;
		if (v == 1)
		{
			um += 1;
		}
		if (v == 2)
		{
			dois += 1;
		}
		if (v == 3)
		{
			tres += 1;
		}
	}
	printf("\nResultado: ");
	if (um > dois && um > tres)
	{
		printf("1");
		return 1;
	}
	if (dois > um && dois > tres)
	{
		printf("2");
		return 2;
	}
	if (tres > um && tres > dois)
	{
		printf("3");
		return 3;
	}
	if(um == 0) {
        if (tres == dois)
        printf("Empate");
	}
	if(dois == 0) {
        if (tres == um)
        printf("Empate");
	}
		if(tres == 0) {
        if (dois == um)
        printf("Empate");
	}
	if (um == dois && dois == tres)
	{
		printf("Empate");
		return 0;
	}
}


int main() {
    exercicio2("7 2 2 1 1 3 3 3");

    return 0;
}

