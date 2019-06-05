#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha
{
    int topo;
    char itens[15];
};

int empty(struct pilha *p);
void push(struct pilha *p, char e);
char pop(struct pilha *p);
char stacktop(struct pilha *p);

int main()
{
    struct pilha *p = malloc(sizeof(struct pilha));

    char frase[15];
    printf("Digite a frase: ");
    scanf("%s", &frase);
    fflush(stdin);

    for(int i=0; i<strlen(frase); i++)
    {
        if(frase[i] != ' ')
        {
            push(p,frase[i]);
        }
        else
        {
            for(int i=0; i<p->topo; i++)
            {
                printf("%s",pop(p));
            }
            printf(" ");
        }
    }

    for(int i=0; i<p->topo; i++)
        {
            printf("%s",pop(p));
        }

    return 0;
}

int empty(struct pilha *p)
{
    if(p->topo == 0)
        return 1;
    else
        return 0;
}

void push(struct pilha *p, char e)
{

    if (p->topo!=15)
    {
        p->itens[p->topo++]=e;
       return 0;
    }
}

char pop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
    return p->itens[--p->topo];
    }
}

char stacktop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
      return p->itens[p->topo-1];
    }
}



