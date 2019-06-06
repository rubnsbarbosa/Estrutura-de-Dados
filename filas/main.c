#include <stdio.h>
#include <stdlib.h>

struct Fila
{
    int itens[10];
    int inicio, fim;
};

int maior=0,menor=0,media=0, m=0, cont=0;

void enqueue(struct Fila *f, int e);
int empty(struct Fila *f);
int dequeue(struct Fila *f);
void MaiorMenorMedia(struct Fila *f);

void enqueue(struct Fila *f, int e)
{
    if(f->fim - f->inicio < 10) /*Indica que a Fila não está cheia*/
    {
        f->itens[f->fim]=e; /*Insere o valor no final da Fila*/
        f->fim++;
    } else
        printf("Fila Cheia!\n");
}

int empty(struct Fila *f) /*Função que verifica se a Fila está vazia*/
{
    if(f->fim - f->inicio == 0)
        return 1;
    else
        return 0;
}

int dequeue(struct Fila *f) /*Remove e retorna o item do inicio*/
{
    if(empty(f))
        printf("Fila Vazia!\n");
    else {
        int aux = f->itens[f->inicio]; /*Variavel para guardar o valor a ser retornado*/
            for(int i = 0; i<f->fim; i++)
    {
        f->itens[i]=f->itens[i+1];
        f->fim--;
        return aux;
    }
}

void MaiorMenorMedia(struct Fila *f)
{
    int i;

        menor=f->itens[0];
        printf("Os numeros sao!\n");
            for(int i=0; i<f->fim; i++)
                printf("%d", f->itens[i]);
            if(menor>f->itens[i]) {
                menor = f->itens[i];
            }
            if(maior<f->itens[i]) {
                maior = f->itens[i];
            }
            media+=f->itens[i];
            cont++;
    }
    m=media/cont;
    printf("\nMaior %d\n",maior);
    printf("\nMenor %d\n",menor);
    printf("\nMedia %d\n",m);
}

int main()
{
    struct Fila *f= malloc(sizeof(struct Fila));

    f->inicio=0;
    f->fim=0;

    int opcao;
    do
    {
         printf("Informe a opcao:\n 1-Inserir na fila\n 2-Remover da fila\n 3-Maior Menor e Media\n 4-Sair\n");
         scanf("%d", &opcao);
         fflush(stdin);
         system("cls");

         switch(opcao)
         {
         case 1:
             {
                int aux;
                printf("Informe o item a ser inserido: ");
                scanf("%d", &aux);
                fflush(stdin);
                enqueue(f, aux);
                break;
             }
         case 2:
            {
                printf("Removido item: %d ", dequeue(f));
                break;
            }
         case 3:
            {
                MaiorMenorMedia(f);
                break;
            }
         case 4: { break; }
         default:
            {
                printf("Opcao invalida!\n");
            }
         }
    } while (opcao != 4);
  return 0;
}
