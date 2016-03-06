#include <stdio.h>
#include <stdlib.h>

void inserirElementosVetor(int vetor[], int n)
{
    printf("Insira os valores do vetor\n");
    int i;
    for(i=0; i<n; i++)
    {
        printf("Vetor[%d] >> ", i);
        scanf("%d", &vetor[i]);
        fflush(stdin);
    }
}

void ordenacaoMetodoBolha(int vetor[], int n)
{
    int i, j, aux = 0;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ordenacaoMetodoInsercao(int vetor[], int n)
{
    int i, j, aux = 0;

    for(i=1; i<=n; i++)
    {
        aux = vetor[i];
        j = i-1;

        while(j>=0 && aux < vetor[j])
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}

void ordenacaoMetodoSelecao(int vetor[], int n)
{
    int i, j, menorIndice, aux = 0;

    for(i=0; i<n-1; i++)
    {
        menorIndice = i;
        for(j=i+1; j<n; j++)
        {
            if(vetor[j] < vetor[menorIndice])
            {
                menorIndice = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[menorIndice];
        vetor[menorIndice] = aux;
    }
}

void ordenacaoMetodoQuickSort(int vetor[], int indiceEsquerda, int indiceDireita)
{
	int i = indiceEsquerda;
	int j = indiceDireita;
	int aux = 0;
	int pivo = vetor[(indiceEsquerda + indiceDireita) / 2];

	while(i <= j)
	{
		while(vetor[i] < pivo)
		{
			i++;
		}

		while(vetor[j] > pivo)
		{
			j--;
		}
		if(i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}

	if(indiceEsquerda < j)
    {
        ordenacaoMetodoQuickSort(vetor, indiceEsquerda, j);
    }
    if(i < indiceDireita)
    {
        ordenacaoMetodoQuickSort(vetor, i, indiceDireita);
    }
}

void exibeVetor(int vetor[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}

int main()
{
    int tamanhoVetor = 10;
    int vetor[tamanhoVetor];

    int opcao;

    do
    {
        printf("Entre com a opcao desejada!\n1 - Inserir elementos no vetor\n2 - Bubble Sort\n3 - Insertion Sort\n");
        printf("4 - Selection Sort\n5 - QuickSort\n6 - Exibir vetor ordenado\n7 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            {
                inserirElementosVetor(vetor, tamanhoVetor);
                break;
            }
        case 2:
            {
                ordenacaoMetodoBolha(vetor, tamanhoVetor);
                printf("Ordenado pelo metodo bolha\n\n");
                break;
            }
        case 3:
            {
                ordenacaoMetodoInsercao(vetor, tamanhoVetor);
                printf("Ordenado pelo metodo insercao\n\n");
                break;
            }
        case 4:
            {
                ordenacaoMetodoSelecao(vetor, tamanhoVetor);
                printf("Ordenado pelo metodo selecao\n\n");
                break;
            }
        case 5:
            {
                ordenacaoMetodoQuickSort(vetor, 0, tamanhoVetor-1);
                printf("Ordenado pelo metodo quicksort\n\n");
                break;
            }
        case 6:
            {
                exibeVetor(vetor, tamanhoVetor);
                break;
            }
        case 7:
            {
                break;
            }
        default:
            {
                printf("Opcao invalida!\n\n");
            }
        }

    } while(opcao != 7);

    return 0;
}
