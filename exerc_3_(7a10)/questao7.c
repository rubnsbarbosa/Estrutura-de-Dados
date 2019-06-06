#include <stdio.h>
#include <stdlib.h>

void troca (int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int a, b;

    printf("\nEntre com o valor A!\n");
    scanf("%d", &a);
    fflush(stdin);

    printf("\nEntre com o valor B!\n");
    scanf("%d", &b);
    fflush(stdin);

    troca(&a,&b);

    printf("\nO valor da troca de A por B eh %d, %d respectivamente\n", a,b);

  return 0;
}
