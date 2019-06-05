#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int *valores;
    int fim,tamanho;
};

int teste(struct pilha *p)
{
    return(p->fim==0);
}

void adiciona(struct pilha *p,int e)
{
    p->valores[p->fim]=e;
    ++p->fim;
}

void remover(struct pilha *p)
{
    if (teste(p))
    {
        printf("\nPilha vazia!\n");
    }else
    {
        printf("%d ",p->valores[--p->fim]);
    }
}

int main()
{
    struct pilha *p=malloc(sizeof(struct pilha));
    p->fim=0;

    printf("Digite o numero em decimal!");
    scanf("%d",&p->tamanho);
    int cont=0,aux=p->tamanho;

    while(aux>1)
    {
        aux=aux/2;
        ++cont;
    }

    p->valores=malloc(sizeof(int[cont+1]));

    while(p->tamanho>=1)
    {
        adiciona(p,p->tamanho%2);
        p->tamanho=p->tamanho/2;
    }

    while (!teste(p))
    {
        remover(p);
    }

    return 0;
}

