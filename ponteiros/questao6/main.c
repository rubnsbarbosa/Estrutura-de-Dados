#include <stdio.h>
#include <stdlib.h>
int i;
int main()
{   int n,*vet1 = malloc(sizeof(int[n]));;

    printf("Entre com o tamanho do vetor!\n");
    scanf("%d",&n);

    printf("Alimente o vetor!\n");
    for (i=0; i<=n; i++)
    {
      vet1[i]=malloc(sizeof(int));
      ler(&(*(vet1+i)));
    }
    printf("Vetor um: \n");
    for (i=0; i<=n; i++)
    {
       printf("%d ",*(vet1+i));
    }

free(vet1);
return 0;
}
void ler( int *x)
{
 printf("vetor um espaco %d ",i);
 scanf("%d",x);
}

