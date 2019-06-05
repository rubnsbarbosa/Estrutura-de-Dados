#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor,*pt;

    printf("Digite o valor!\n");
    scanf("%d",&valor);

    pt=&valor;
    *pt=(*pt)*(*pt)*(*pt)*(*pt)*(*pt);

    printf("%d",valor);
    return 0;
}

