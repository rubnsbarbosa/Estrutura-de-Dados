#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int topo;
    float itens[15];
    float media;
    float maior, menor;
};

int empty(struct pilha *p);
void push(struct pilha *p, float e);
float pop(struct pilha *p);
float stacktop(struct pilha *p);

int main()
{
    struct pilha *p = malloc(sizeof(struct pilha));
    p->topo=0;
    p->maior=0;
    p->menor=9999;
    p->media=0;

    float num;
    for(int i=0; i<15; i++)
    {
        printf("\nDigite o %d elemento da pilha: ",i+1);
        scanf("%f", &num);
        push(p,num);

        if(p->maior < num)
        {
            p->maior = num;
        }
        if(p->menor > num)
        {
           p->menor = num;
        }
        p->media+=num;
    }

    printf("\nPilha:\n");
    printf("O menor e: %.2f\n ", p->menor);
    printf("A maior e: %.2f\n ", p->maior);
    printf("A media e: %.2f\n ", p->media/15);

    return 0;
}

int empty(struct pilha *p)
{
    if(p->topo == 0)
        return 1;
    else
        return 0;
}

void push(struct pilha *p, float e)
{
    if(p->topo == 15)
        printf("Pilha Cheia!");
    else
    {
    return   p->itens[p->topo++]=e;
    }
}

float pop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
    return     p->itens[--p->topo];
    }
}

float stacktop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
      return p->itens[p->topo-1];
    }
}
