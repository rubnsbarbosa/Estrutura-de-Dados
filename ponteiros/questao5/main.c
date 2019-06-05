#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont, i,j, tam1, tam2, *vet1=malloc(sizeof(int[tam1])), *vet2=malloc(sizeof(int[tam2]));

    printf("Entre com o tamanho do primeiro vetor!\n");
    scanf("%d",&tam1);

    printf("Entre com o tamanho do segundo vetor!\n");
    scanf("%d",&tam2);

    printf("Entre com os elementos do primeiro vetor!\n");
        for(int i=0; i<tam1; i++)
        {
            vet1[i]=malloc(sizeof(int));
            scanf("%d",&vet1[i]);
        }

    printf("Entre com os de elementos do segundo vetor!\n");
        for(int j=0; j<tam2; i++)
        {
            vet2[j]=malloc(sizeof(int));
            scanf("%d",&vet2[j]);
        }

    printf("Diferenca do vetor um para o vetor dois!\n");
    for(int i=0; i<tam1; i++)
    {
        cont=0;

        for(int j=0; j<tam2; i++)
        {
            if (vet1 == vet2)
            cont++;
            break;
        }
      if (!cont)
	 printf("%d\n",*(vet1+i));
    }

    printf("Intersecao do vetor um e o vetor dois!\n");
    for (i=0; i<=tam1; i++)
    {
        for (j=0; j<=tam2; j++)
            {
                if (*(vet1+i)==*(vet2+j))
                printf("%d, ",*(vet1+i));
                break;
            }
    }

    return 0;
}
