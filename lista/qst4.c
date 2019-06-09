#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *proximo;
};

void insereVetor(struct no **noInicial, int vetor)
{

    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor = vetor;
    novoNo->proximo = noInicial;
    *noInicial = novoNo;
}

void imprime(struct no **noInicial)
{
    if(*noInicial == NULL)
    {
        printf("Lista vazia!");
    }
    else
    {
        struct no *aux = *noInicial;
        while(aux != NULL)
        {
            printf("%d\n",aux->valor);
            aux = aux->proximo;
        }
    }
}

int main()
{
    struct no *no = NULL;

    int *vetor;
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    fflush(stdin);
    vetor = malloc(tam * sizeof(int));

    for(int i = 0; i<tam; i++)
        {
        printf("Digite o valor %d a ser inserido: ",i+1);
        scanf("%d",&vetor[i]);
        }
    for(int i=0; i<tam; i++)
      {
        insereVetor(&no,vetor[i]);
      }
    imprime(&no);


  return 0;
}
