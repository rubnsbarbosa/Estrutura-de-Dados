#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char valor;
    struct no *proximo;
} Celula;

void insereInicio(struct no **noInicial, char letra)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor = letra;
    novoNo->proximo = *noInicial;
    *noInicial = novoNo;
}

void insereFinal(struct no **noFinal, char letra)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor = letra;
    novoNo->proximo = NULL;

    if(*noFinal == NULL)
    {
        *noFinal = novoNo;
    }
    else
    {
        struct no *aux = *noFinal;
        while(aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
    aux->proximo = novoNo;
    }
}

void insereEntreDuasLetras(struct no **anterior, char letraNova, char letraAnterior)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor = letraNova;

    struct no *aux = *anterior;
    while(aux->proximo != NULL)
    {
        if(aux->valor == letraAnterior)
        {
            novoNo->proximo = aux->proximo;
            aux->proximo = novoNo;
        }
        aux = aux->proximo;
    }
}

Celula *excluiElemento(Celula *lista, char valor)
{
    Celula *aux, *anterior;
    anterior = lista;
    if(anterior->valor == valor){
        aux = anterior->proximo;
        free(anterior);
        return aux;
    }

    for(aux = anterior->proximo; aux != NULL; aux = aux->proximo)
    {
        if(aux->valor == valor)
        {
            anterior->proximo = aux->proximo;
            free(aux);
            return lista;
        }
        anterior = anterior->proximo;
    }
    return lista;
}

void removeInicio(struct no **noInicial)
{
    struct no *aux = *noInicial;
    *noInicial = (*noInicial)->proximo;
    free(aux);
}

void imprimeLista(struct no **noInicial)
{
    if(noInicial == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        printf("\n-------Imprimindo\n");
        struct no *aux = *noInicial;
        while(aux != NULL)
        {
            printf("%c", aux->valor);
            aux = aux->proximo;
        }
    }
}

int main()
{
    struct no *no = malloc(sizeof(struct no));

    insereFinal(&no, 'A');
    imprimeLista(&no);

    insereInicio(&no, 'B');
    imprimeLista(&no);

    insereFinal(&no, 'C');
    imprimeLista(&no);

    insereFinal(&no, 'D');
    imprimeLista(&no);

    insereEntreDuasLetras(&no, 'E', 'A');
    imprimeLista(&no);

    excluiElemento(no, 'C');
    imprimeLista(&no);

    insereFinal(&no, 'F');
    imprimeLista(&no);

    insereInicio(&no, 'G');
    imprimeLista(&no);

    excluiElemento(no, 'F');
    imprimeLista(&no);

    removeInicio(&no);
    imprimeLista(&no);

    insereEntreDuasLetras(&no, 'H', 'A');
    imprimeLista(&no);

    excluiElemento(no, 'A');
    imprimeLista(&no);

    insereEntreDuasLetras(&no, 'I', 'E');
    imprimeLista(&no);

    insereFinal(&no, 'J');
    imprimeLista(&no);

    insereEntreDuasLetras(&no, 'K', 'B');
    imprimeLista(&no);

    excluiElemento(no, 'D');
    excluiElemento(no, 'K');
    excluiElemento(no, 'I');
    removeInicio(&no);
    imprimeLista(&no);

    insereFinal(&no, 'L');
    imprimeLista(&no);

    printf("\n");
/*
    int opcao;
    do
    {
        printf("\nEntre com a opcao desejada\n1 - Inserir no inicio da lista\n2 - Inserir no final da lista");
        printf("\n3 - Inserir no entre duas letras\n4 - Excluir elemento\n5 - Exclui Inicio");
        printf("\n6 - Mostrar Lista\n7 - Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            {
                char letra1;
                printf("Entre com a letra do no: ");
                scanf(" %c", &letra1);
                fflush(stdin);

                insereInicio(&no, letra1);
                break;
            }
        case 2:
            {
                char letra2;
                printf("Entre com a letra do no: ");
                scanf(" %c", &letra2);
                fflush(stdin);

                insereFinal(&no, letra2);
                break;
            }
        case 3:
            {
                char letraNova;
                printf("Entre com a nova letra: ");
                scanf(" %c", &letraNova);
                fflush(stdin);

                char letraAntecessor;
                printf("Inserir letra anterior: ");
                scanf(" %c", &letraAntecessor);
                fflush(stdin);

                insereEntreDuasLetras(&no, letraNova, letraAntecessor);
                break;
            }
        case 4:
            {
                char letraExcluida;
                printf("Entre com a letra que ira excluir: ");
                scanf(" %c", &letraExcluida);
                fflush(stdin);

                excluiElemento(no, letraExcluida);
                break;
            }
        case 5:
            {
                removeInicio(&no);
                break;
            }
        case 6:
            {
                imprimeLista(&no);
                break;
            }
        case 7:
            {
                break;
            }
        default:
            {
                printf("Opcao invalida!\n\n");
            }
        }

    } while(opcao != 7);
*/
    return 0;
}
