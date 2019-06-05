#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int topo1,topo2;
    int itens[20];
};

int empty(struct pilha *p);
void push1(struct pilha *p, int e);
void push2(struct pilha *p, int e);
int pop1(struct pilha *p);
int pop2(struct pilha *p);
void stacktop1(struct pilha *p);
void stacktop2(struct pilha *p);

int empty(struct pilha *p)
{
    if(p->topo1==0 || p->topo2 == 10)
        return 1;
    else
        return 0;
}

void push1(struct pilha *p, int e)
{
    if(p->topo1==10)
        printf("Pilha cheia!");
    else
    {
        p->itens[p->topo1++]=e;
    }
}

void push2(struct pilha *p, int e)
{
    if(p->topo2==20)
        printf("Pilha cheia!");
    else
    {
        p->itens[p->topo2++]=e;
    }
}

int pop1(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[--p->topo1];
    }
}

int pop2(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[--p->topo2];
    }
}

void stacktop1(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[p->topo1-1];
    }
}

void stacktop2(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[p->topo2-1];
    }
}

int main()
{
    struct pilha *p = malloc(sizeof(struct pilha));
    p->topo1=0;
    p->topo2=10;

    do
    {
        printf("!Entre com a opcao desejada \n1- Inserir elementos na pilha 1\n2- Inserir elementos na pilha 2\n3- Remover elementos da pilha 1\n4- Remover elementos da pilha 2\n5- Mostra o topo da pilha 1\n6- Mostra o topo da pilha 2");

        switch
        {
            case: 1
            {
                break;
            }
            case: 2
            {
                break;
            }
            case: 3
            {
                break;
            }
            case: 4
            {
                break;
            }
            case: 5
            {
                break;
            }
        }
    } while(1);
    return 0;
}
