#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha
{
    int *valores;
    int fim_1,fim_2;
    int tamanho;
    int lado;
};

int vazia (struct pilha *p)
{
    return (p->fim_1==0 && p->fim_2==p->tamanho);
}

int retirar (struct pilha *p)
{
    if (vazia(p))
    {
        printf("\nPilha vazia!\n");
    }else
    {
        printf("Deseja retirar dos 1-impares ou 2-pares!");
        int aux;
        scanf("%d",&aux);

        if (aux==1)
        {
            printf("\nO valor removido eh: %d\n",p->valores[0]);
            mover_base(p,p->fim_1,-1);
            --p->fim_1;
        }
        else
        {
            printf("\nO valor removido eh: %d\n",p->valores[p->tamanho]);
            mover_topo(p,p->fim_2,p->tamanho+1);
            ++p->fim_2;
        }
    }
}

void adicionar(struct pilha *p)
{
    if (p->fim_2==p->fim_1)
    {
        printf("\nA pilha esta lotada!\n");
    }else
    {
        int valor;
        printf("\nDigite o valor que deseja adicionar:");
        scanf("%d",&valor);

        if (valor%2==0)
        {
            mover_base(p,p->fim_1,0);
            p->valores[0]=valor;
            ++p->fim_1;
        }else
        {
            mover_topo(p,1,p->fim_2,p->tamanho);
            p->valores[p->tamanho]=valor;
            --p->fim_2;
        }
    }
}

void apresenta (struct pilha *p)
{
    if (!vazia(p))
    {
        printf("\nSua pilha! Impares \n");
        for (int i=0;i<p->fim_1;i++)
        {
            printf("%d ",p->valores[i]);
        }
        printf("\nSua pilha! Pares \n");
        for (int i=p->tamanho;i>p->fim_2;i--)
        {
                printf("%d ",p->valores[i]);
        }
    }else
        printf("\nPilha vazia!\n");
}

void mover_base(struct pilha *p,int fim,int inicio)
{
    for (int i=inicio;i>fim;++i)
    {
        p->valores[i-1]=p->valores[i];
    }
}
void mover_topo(struct pilha *p,int fim,int inicio)
{
    for (int i=inicio;i<fim;i++)
    {
        p->valores[i+1]=p->valores[i];
    }
}


int main()
{
    struct pilha *p=malloc(sizeof(struct pilha));

    printf("Digite o tamanho que deseja pra fila!");
    scanf("%d",&p->tamanho);

    p->valores=malloc(sizeof(int[p->tamanho]));
    p->fim_1=0;
    //p->tamanho=p->tamanho;
    p->fim_2=p->tamanho;

    int testa;

    do{
        printf("Digite a opcao correspondente no menu:");
        printf("\n01-Adicionar valor\n02-Reirar valor\n03-Mostrar pilha");
        scanf("%d",&testa);
        switch (testa)
        {
        case 1:
            {
                adicionar(p);
                break;
            }
        case 2:
            {
                retirar(p);
                break;
            }
        case 3:
            {
                apresenta(p);
                break;
            }
        default:
            {
                printf("\nO valor digitado nao consta no menu!");
                continue;
            }
        }
        }while (1);
    return 0;
}
