#include <stdio.h>

void selectionSort();

int main()
{
	selectionSort();

	return 0;
}

void selectionSort()
{
	int vetor[9] = {5, 4, 3, 2, 1, 0, 9, 8, 7};
	int aux = 0;
	int i;
	for(i = 0; i < 9; i++)
	{
		int j;
		for(j = i+1; j < 9; j++)
		{
			if(vetor[j] < vetor[i])
			{
				aux = vetor[j];
				vetor[j] = vetor[i];
				vetor[i] = aux;
			}
		}
	}
	//laço pra imprimir
	int k;
   for(k = 0; k < 9; ++k)
   {
       printf("Vetor[%d] = %d\n", k, vetor[k]);
   }
}
