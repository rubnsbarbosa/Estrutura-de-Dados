#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *proximo;
};

void insereInicio(struct no **noInicial, int e)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor = e;
    novoNo->proximo = *noInicial;
    *noInicial = novoNo;
}

void imprime(struct no **noInicial)
{
    if(*noInicial == NULL)
    {
        printf("Lista vazia!");
    }
     else

    {
        struct no *aux = *noInicial;
        int menor;
        menor = aux->valor;
        while(aux!=NULL)
        {
                if(aux->valor < menor)
                {
                    menor = aux->valor;
                }
                   aux = aux->proximo;
        }
      printf("O menor no eh: %d\n", menor);
    }
}

int main()
{

    struct no *no = NULL;

    int opcao;
    do
    {
         printf("\nEntre com a opcao desejada\n\n1-Inserir no\n2-Mostrar menor no\n3-Sair!\n");
         scanf("%d", &opcao);
         fflush(stdin);
         system("cls");


         switch(opcao)
         {
         case 1:
            {
                int aux;
                printf("Entre com o valor do no: ");
                scanf("%d", &aux);
                fflush(stdin);

                insereInicio(&no, aux);
                break;
            }
         case 2:
            {
                imprime(&no);
                break;
            }
         case 3:
            {
                break;
            }
         }
    } while(opcao != 3);
  return 0;
}
