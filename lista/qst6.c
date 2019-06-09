#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *proximo;
};

void inserir(struct no **noInicial, int e)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor=e;
    novoNo->proximo=noInicial;
    *noInicial=novoNo;
}

void concatenar(struct no **noInicial1, struct no **noInicial2)
{
   /* struct no *aux = *noInicial1;
    while(aux->proximo != NULL)
        aux = aux->proximo;
        aux->proximo = noInicial2->proximo;*/
    if (*noInicial1 == NULL)
        *noInicial1 = (*noInicial2)->proximo;
    else
    {
        if ((*noInicial1)->proximo == NULL)
        {
            (*noInicial1)->proximo = (*noInicial2)->proximo;
        }
        else
        {
            struct no *aux = *noInicial1;
            while (aux->proximo->proximo != NULL)
                aux = aux->proximo;
                aux->proximo = (*noInicial2)->proximo;
        }
//      free(aux);
    }
}

int main()
{
    struct no *no1 = malloc(sizeof(struct no));
    no1->proximo=NULL;
    struct no *no2 = malloc(sizeof(struct no));
    no2->proximo=NULL;

    int opcao;
    do
    {
        printf("Entre com a opcao desejada!\n1-Inserir\n2-Concatenar\n3-Sair");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");

        switch(opcao)
        {
        case 1:
            {
                int aux;
                printf("Digite o valor do no ");
                scanf("%d", &aux);
                fflush(stdin);

                int opcao1;
                printf("Qual no vc quer inserir? ");
                scanf("%d", &opcao1);
                fflush(stdin);

                    switch(opcao1)
                    {
                    case 1:
                        {
                            inserir(&no1,aux);
                        }
                    case 2:
                        {
                            inserir(&no2,aux);
                        }
                    default:
                        {
                            printf("Opcao invalida!");
                        }
                    }
                break;
            }
        case 2:
            {
                concatenar(&no1,&no2);
                break;
            }
        case 3:
            {
                break;
            }
        default:
            {
                printf("Opcao Invalida");
            }
        }

    }while(opcao != 3);
}
