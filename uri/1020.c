#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N = 0, ano = 0, auxMes = 0, mes = 0, auxDia = 0, dia = 0;	
	scanf("%d", &N);

	ano = N / 365;
	auxMes = ano * 365;
	mes = ((N - auxMes) / 30);
	auxDia = mes * 30;
	dia = ((N - auxMes) - auxDia);

	printf("%d ano(s)\n", ano);
	printf("%d mes(es)\n", mes);
	printf("%d dia(s)\n", dia);

	return 0;
}
