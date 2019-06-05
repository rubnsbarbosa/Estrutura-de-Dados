#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
    int itens[20];
    int top1,top2;
    int tipo;
};

void push (struct Pilha *P, int e)
{
    if (P->top1!=10 && P->tipo==1)
    {
        P->itens[P->top1++]=e;
        return 0;
    }
    else    if (P->top2!=20 && P->tipo==2)
    {
        P->itens[P->top2++]=e;
        return 0;
    }
    else
            printf ("Filha Full!");
}


void pop (struct Pilha *P)
{
    if (!(empty(P)) && P->tipo==1)
        return P->itens[--P->top1];

    else

    if (!(empty(P)) && P->tipo==2)
        return P->itens[--P->top2];
    else
            printf("Fila null!");
}


int empty (struct Pilha *P)
{
    if ( P->top1==0 && P->tipo==1 )
            return 1;
    else

    if ( P->top2==10 && P->tipo==2 )
            return 1;
    else
            return 0;
}

int stackpop(struct Pilha *P)
{
    if (!(empty(P)) && P->tipo==1)
        return P->itens[P->top1-1];

    else

    if (!(empty(P)) && P->tipo==2)
        return P->itens[P->top2-1];
    else
            printf("Fila null!");
}


int main()
{
        struct Pilha *P = malloc(sizeof(struct Pilha));
        P->top1=0;
        P->top2=10;
        int opt,elemento;

    do{
            INIT:
            printf("Digite a pilha que deseja usar! 1 ou 2:\n ");
            scanf("%d",&P->tipo);
            if((P->tipo != 1) && (P->tipo != 2)) goto INIT; else goto MENU;
        MENU:
        printf("Digite a opcao correspondente no menu:");
        printf("\n01-Adicionar valor\n02-Reirar valor\n03-Mostrar pilha\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            {
                printf("Digite o elemento da pilha: ");
                scanf("%d", &elemento); fflush(stdin);
                push(P,elemento);
                break;
            }
        case 2:
            {
                pop(P);
                break;
            }
        case 3:
            {
                printf("%d\n",stackpop(P));
                break;
            }
        default:
            {
                printf("\nO valor digitado nao consta!");
                continue;
            }
        }
        }while (1);
    return 0;
}
