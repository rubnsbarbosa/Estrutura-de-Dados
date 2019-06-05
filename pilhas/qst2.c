#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int STACKSIZE;
    int *itens;
};

int empty(struct pilha *p)
{
    if(p->itens[0] == 1)
        return 1;
    else
        return 0;
}

void push(struct pilha *p, int e)
{
    if(p->itens[0] == p->STACKSIZE)
        printf("Pilha cheia!");
    else
    {
        p->itens[p->itens[0]++]=e;
    }
}

int pop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[--p->itens[0]];
    }
}


void stacktop(struct pilha *p)
{
    if(empty(p))
        printf("Pilha vazia!");
    else
    {
        return p->itens[p->itens[0]-1]
    }
}

int main()
{
    struct pilha *p = malloc(sizeof(struct pilha));

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &p->STACKSIZE);
    fflush(stdin);

    p->itens = malloc(++STACKSIZE * sizeof(int))
    p->itens[0]=0;

    int opcao;
    do
    {
        printf("Entre com a opcao desejada\n\n1 - Inserir elemetos na pilha\n2 - Remover elementos da pilha\n3 - Mostrar o topo da pilha\n4 - Sair");

        switch
        {
            case 1:
            {
                int aux;
                printf("Digite um elemento: ");
                scanf("%d", &aux);
                fflush(stdin);

                push(p,aux);
                break;
            }
            case 2:
            {
                printf("Removido o elemento: %d ",pop(p));
                break;
            }
            case 3:
            {
                printf("Topo da pilha: %d ",stacktop(p));
                break;
            }
            case 4:
            {
                break;
            }
            default:
                {
                    printf("Opcao invalida!");
                    break;
                }
        }
    } while(opcao != 4);
    return 0;
}
