#include <stdio.h>
#include <stdlib.h>

void armazenaElementosFaixaEntreDezQuarenta(int vetorY[], int n);
void exibeVetor(int vetor[], int n);
void armazenaElementosPosicoesPares(int vetorW[], int n);
void pesquisaSequencial(int vetorX[], int n, int numeroPesquisado);
void encontraMaiorElemento(int vetor[], int n);
void encontraMenorElemento(int vetor[], int n);

int main()
{
    int nElementos, elementoPesquisadoVetor;
    int vetorX[nElementos];

    printf("Digite o elemento para ser pesquisado no vetor: ");
    scanf("%d", &elementoPesquisadoVetor);
    fflush(stdin);

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &nElementos);
    fflush(stdin);

    int i;
    for(i=0; i<nElementos; ++i)
    {
        printf("Digite o valor do vetor[%d]:", i+1);
        scanf("%d", &vetorX[i]);
        fflush(stdin);
    }

    exibeVetor(vetorX, nElementos);
    armazenaElementosFaixaEntreDezQuarenta(vetorX, nElementos);
    armazenaElementosPosicoesPares(vetorX, nElementos);
    pesquisaSequencial(vetorX, nElementos, elementoPesquisadoVetor);
    encontraMaiorElemento(vetorX, nElementos);
    encontraMenorElemento(vetorX, nElementos);

    return 0;
}

void armazenaElementosFaixaEntreDezQuarenta(int vetorY[], int n)
{
    printf("\nVetor Y contendo os numeros que estao entre 10 e 40\n");
    int i, contador=0;
    for(i=0; i<n; ++i)
    {
        if((vetorY[i] < 40) && (vetorY[i] > 10))
        {
            contador++;
            printf("Vetor[%d] = %d\n", i, vetorY[i]);
        }
    }
}

void armazenaElementosPosicoesPares(int vetorW[], int n)
{
    printf("\nVetor W contendo os numeros que estao nas posicoes pares\n");
    int i, contador=0;
    for(i=0; i<n; ++i)
    {
        if(vetorW[i]%2 == 0)
        {
            contador++;
            printf("Vetor[%d] = %d\n", i, vetorW[i]);
        }
    }
}

void pesquisaSequencial(int vetorX[], int n, int numeroPesquisado)
{
    printf("\nPesquisa de um determinado elemento Z no vetor X\n");
    int i, encontrou=0;
    for(i=0; i<n; ++i)
    {
        if(numeroPesquisado == vetorX[i])
        {
            encontrou++;
            printf("Vetor[%d] contem elemento pesquisado elemento encontrado :: %d\n",i ,numeroPesquisado);
        }
        else
        {
            printf("Vetor[%d] nao contem elemento pesquisado\n", i);
        }
    }
}

void encontraMaiorElemento(int vetor[], int n)
{
    printf("\n");
    int i, maior=0;
    for(i=0; i<n; ++i)
    {
        if(maior < vetor[i])
        {
            maior = vetor[i];
        }
    }
    printf("Maior elemento encontrado :: %d\n", maior);
}

void encontraMenorElemento(int vetor[], int n)
{
    int i, menor;
    for(i=0; i<n; ++i)
    {
        if(vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    printf("Menor elemento encontrado :: %d\n", menor);
}

void exibeVetor(int vetor[], int n)
{
    int i;
    for(i=0; i<n; ++i)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}
