#include <stdio.h>
#include <stdlib.h>

int medidasDoRatangulo(int L1, int L2, int *A, int *P)
{
   *A=L1*L2;
   *P=2*(L1+L2);

    if (L1==L2){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int lado1, lado2,A,P;
    printf("\nEntre com lado 1!\n");
    scanf("%d", &lado1);
    fflush(stdin);

    printf("\nEntre com lado 2!\n");
    scanf("%d", &lado2);
    fflush(stdin);


    printf("\nO retorno eh !%d\n", medidasDoRatangulo(lado1,lado2,&A,&P));
    printf("\nA area e %d e o Perimetro eh %d\n",A,P);
  return 0;
}
