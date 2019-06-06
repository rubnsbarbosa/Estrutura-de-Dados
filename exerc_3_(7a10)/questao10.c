#include <stdio.h>
#include <stdlib.h>

void soma(int *value1, int *value2, int *soma1)
{
    *soma1 = *value1 + *value2;
}

void purchasePrice(int *itemPrice, int *taxRate, int *price)
{
    *price = *itemPrice + (*itemPrice * *taxRate / 0.01);
}

int main()
{
    int valor1, valor2,somax=0;

    printf("\nEntre com o valor 1!\n");
    scanf("%d", &valor1);
    fflush(stdin);

    printf("\nEntre com o valor 2!\n");
    scanf("%d", &valor2);
    fflush(stdin);

    soma(&valor1, &valor2, &somax);

    printf("\nA soma e %d!\n", somax);

    int precoItem, taxImposto,precox=0;

    printf("\nEntre com o preco do item!\n");
    scanf("%d", &precoItem);
    fflush(stdin);

    printf("\nEntre com a taxa do imposto!\n");
    scanf("%d", &taxImposto);
    fflush(stdin);

    soma(&precoItem, &taxImposto, &precox);

    printf("\nO valor do item e %d!\n", precox);

  return 0;
}
