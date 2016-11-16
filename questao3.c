#include <stdio.h>
#include <stdlib.h>

void exibeVetor(int vetor[], int n);
int pesquisaSequencial(int vetor[], int tamanho, int numeroPesquisado);

int main()
{
    int tamanhoA = 0;
    printf("Digite o tamanho do vetor A: ");
    scanf("%d", &tamanhoA);
    fflush(stdin);

    int vetorA[tamanhoA];
    int valor = 0;
    int i;
    for(i=0; i<tamanhoA; i++)
    {
        printf("Digite o valor %d do vetor A:", i);
        scanf("%d", &valor);
        fflush(stdin);
        vetorA[i] = valor;
    }

    printf("\n");

    int tamanhoB = 0;
    printf("Digite o tamanho do vetor B: ");
    scanf("%d", &tamanhoB);
    fflush(stdin);

    int vetorB[tamanhoB];
    for(i=0; i<tamanhoB; i++)
    {
        printf("Digite o valor %d do vetor B:", i);
        scanf("%d", &valor);
        fflush(stdin);
        vetorB[i] = valor;
    }

    //intercalar os elementos dos vetores A e B
    int vetorC[tamanhoA + tamanhoB];
    int indiceA = 0;
    int indiceB = 0;

    i = 0;
    while(i < tamanhoA + tamanhoB)
    {
        if(indiceA < tamanhoA)
        {
            vetorC[i] = vetorA[indiceA];
            indiceA++;
            i++;
        }
        if(indiceB < tamanhoB)
        {
            vetorC[i] = vetorB[indiceB];
            indiceB++;
            i++;
        }
    }

    exibeVetor(vetorC, tamanhoA + tamanhoB);

    printf("Digite um numero para ser pesquisado: ");
    int numeroPesquisado, resultado;
    scanf("%d", &numeroPesquisado);
    resultado = pesquisaSequencial(vetorC, tamanhoA + tamanhoB, numeroPesquisado);

    if(resultado >= 0)
    {
        printf("Numero encontrado na posicao %d", resultado);
    }
    else
    {
        printf("Numero nao encontrado");
    }

    return 0;
}

void exibeVetor(int vetor[], int n)
{
    int i;
    for(i=0; i<n; ++i)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}

int pesquisaSequencial(int vetor[], int tamanho, int numeroPesquisado)
{
    int i;
    for(i = 0; i < tamanho; i++)
    {
        if(vetor[i] == numeroPesquisado)
        {
            return i;
        }
    }
    return -1;
}
