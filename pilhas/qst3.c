#include <stdio.h>
#include <stdlib.h>


struct pilha
{
    int topo;
    int itens[10];
};

int empty(struct pilha *p)
{
    if(p->topo == 0)
        return 1;
    else
        return 0;
}

void push(struct pilha *p, int e)
{
    if(p->topo == 10)
        printf("Pilha cheia!");
    else
    {
        p->itens[p->topo++]=e;
    }
}

int pop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[--p->topo];
    }
}

int stacktop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[p->topo-1];
    }
}

int main()
{
    struct pilha *p1 = malloc(sizeof(struct pilha));
    struct pilha *p2 = malloc(sizeof(struct pilha));
    p1->topo=0;
    p2->topo=0;

    int num;
    printf("Digite 10 numeros: ");

    for(int i=0; i<10; i++)
    {

        scanf("%d", &num);

        if(num % 2 == 0)
        {
            push(p1,num);
        }
        else
        {
            push(p2,num);
        }
    }


    printf("\nOs numeros pares sao! ");
        for(int i=0; i<p1->topo; i++)
        {
            printf("%d\n", pop(p1));
        }

    printf("\nOs numeros impares sao!");
        for(int i=0; i<p2->topo; i++)
        {
            printf("%d\n", pop(p2));
        }

return 0;
}
