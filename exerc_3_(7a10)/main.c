#include <stdio.h>
#include <stdlib.h>
//devolve o menor deles em A, o maior em C, e o valor do meio em B.

void mmm(int *a,int *b,int *c)
{
 int aux;
    if((*a>= *b) && (*b >= *c))
      {
       aux= *a;
       *a = *c;
       *c = aux;
      }
    if((*a >= *c) && (*c >= *b))
    {
        aux = *b;
        *b = *c;
        *c = *a;
        *a = aux;
    }
    if ((*b >= *a) && (*a >= *c))
    {
        aux = *a;
        *a = *c;
        *c = *b;
        *b = aux;
    }
}

int main()
{
    int valorA, valorB, valorC;
    printf("Entre com o valor 1!\n");
    scanf("%d", &valorA);
    fflush(stdin);

    printf("Entre com o valor 2!\n");
    scanf("%d", &valorB);
    fflush(stdin);

    printf("Entre com o valor 3!\n");
    scanf("%d", &valorC);
    fflush(stdin);

    mmm(&valorA, &valorB, &valorC);

    printf("%d %d %d",valorA, valorB, valorC);
    return 0;
}

