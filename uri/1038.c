#include <stdio.h>
#include <stdlib.h>

int main()
{
	int codigo = 0, qtde = 0;
	float total = 0.0;
	scanf("%d %d", &codigo, &qtde);

	if(codigo == 1)
	{
		total = (qtde * 4.00);
		printf("Total: R$ %.2f\n", total);
	}
	else if(codigo == 2)
	{
		total = (qtde * 4.50);
		printf("Total: R$ %.2f\n", total);
	}
	else if(codigo == 3)
	{
		total = (qtde * 5.00);
		printf("Total: R$ %.2f\n", total);
	}
	else if(codigo == 4)
	{
		total = (qtde * 2.00);
		printf("Total: R$ %.2f\n", total);
	}
	else if(codigo == 5)
	{
		total = (qtde * 1.50);
		printf("Total: R$ %.2f\n", total);
	}

	return 0;
}
