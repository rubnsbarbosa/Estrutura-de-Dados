#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *proximo;
};

void insere(struct no **noInicial, int e)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor = e;
    novoNo->proximo = noInicial;
    *noInicial = novoNo;
}

int remover(struct no **noInicial, int n)
{
    if(*noInicial == NULL)
        printf("Lista vazia!\n");
    else
    {
        struct no *aux = *noInicial;
        *noInicial = (*noInicial)->proximo;
        int valorRem = aux->valor;
        free(aux);
        if(n> aux->valor)
        return remover(&aux,--n);
        else
        return valorRem;
    }
}

int main()
{
    struct no *no = NULL;

    int opcao;

    do
    {
        printf("Entre com a opcao desejada!\n\n1-Inserir elementos no no\n2-Remover no\n3-Sair\n");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");

        switch(opcao)
        {
        case 1:
            {
                int aux;
                printf("Digite o no: ");
                scanf("%d", &aux);
                fflush(stdin);
                system("pause");

                insere(&no, aux);
                break;
            }
        case 2:
            {
                int aux;
                printf("Digite qnts nos vc quer remover: ");
                scanf("%d", &aux);
                fflush(stdin);
                system("pause");

                for(int i=0; i<aux; i++)
                {
                    remover(&no,aux);
                }
               break;
            }
        case 3:
            {
                break;
            }
            default:
            {
                printf("Opcao invalida!\n");
            }
        }
    }while(opcao != 3);
  return 0;
}
