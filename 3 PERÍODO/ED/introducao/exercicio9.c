#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exercicio9(const char *entrada)
{
	int n, count, aux = 0, tamanho = 0, i = 0;
	float mediana = 0;

	sscanf(entrada, "%d%n", &n, &count);
	entrada += count;
	int vetor[n];
	tamanho = n;
	    int temp = 0;
	for(n; n > 0; n--) {
		sscanf(entrada, "%d%n", &temp, &count);
		vetor[i] = temp;
		printf(" %d", vetor[i]);
		entrada += count;
		i++;
    }

n = tamanho;
 for(int i=0;i<tamanho-1;i++){
        for(int j=i+1;j<tamanho;j++){

            if(vetor[i] > vetor[j]){

                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    if(tamanho%2){
         mediana = vetor[tamanho/2];
         printf("Mediana: %2.1f \n", mediana);
    } else {
         mediana = (vetor[tamanho/2-1]+vetor[tamanho/2])/2;
         printf("Mediana: %2.1f \n", mediana);
    }






	    printf("\n\nDepois:\n\nV = { %d, ", vetor[0]);
        for (int i = 1; i < tamanho; i++)
         printf(", %d", vetor[i]);

   printf(" }");

}

int main()
{
	exercicio9("5 8 3 6 1 4");

	return 0;
}
