#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *proximo;
};


void insereInicio(struct no **NoInicial, int e)
{
    struct no *novono = malloc(sizeof(struct no));
    novono->valor =e;
    novono->proximo =*NoInicial;
    *NoInicial = novono;
}

void imprimeLista(struct no **NoInicial)
{
    if (*NoInicial == NULL)
        printf("Lista vazia!");
    else
    {
        int cont=0;
        struct no *aux = *NoInicial;
        while(aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->proximo;
            cont++;
        }
      printf("O numero de celulas eh: %d ", cont);
    }
}

int main()
{
    struct no *no = NULL;

    int opcao;
    do
    {
        printf("Digite a opcao desejada\n1-Inserir celulas\n2-Mostrar celulas!\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                {
                    int aux;
                    printf("Digite um elemento: ");
                    scanf("%d", &aux);
                    fflush(stdin);

                    insereInicio(&no,aux);

                    break;
                }
            case 2:
                {
                    imprimeLista(&no);
                    break;
                }
            case 3:
                {
                    break;
                }
            default:
                {
                    printf("Opcao invalida!");
                    break;
                }
            }
    }while(opcao != 2);

    return 0;
}

