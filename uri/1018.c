#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N = 0, notasCem = 0, auxCem = 0, notasCinquenta = 0, auxCinquenta = 0, auxC = 0, notasVinte = 0, auxVinte = 0, auxV = 0;
	int notasDez = 0, auxDez = 0, auxD = 0, notasCinco = 0, auxCinco = 0, auxFive = 0, notasDois = 0, auxDois = 0, auxTwo = 0, ntsUm = 0;
	scanf("%d", &N);

	notasCem = N / 100;
	auxCem = notasCem * 100;

	notasCinquenta = N - auxCem;
	auxCinquenta = notasCinquenta / 50;
	auxC = auxCinquenta * 50;

	notasVinte = (N - (auxCem + auxC));
	auxVinte = notasVinte / 20;
	auxV = auxVinte * 20;

	notasDez = (N - (auxCem + auxC + auxV));
	auxDez = notasDez / 10;
	auxD = auxDez * 10;

	notasCinco = (N - (auxCem + auxC + auxV + auxD));
	auxCinco = notasCinco / 5;
	auxFive = auxCinco * 5;

	notasDois = (N - (auxCem + auxC + auxV + auxD + auxFive));
	auxDois = notasDois / 2;
	auxTwo = auxDois * 2;

	ntsUm = (N - (auxCem + auxC + auxV + auxD + auxFive + auxTwo));

	printf("%d\n", N);
	printf("%d nota(s) de R$ 100,00\n", notasCem);
	printf("%d nota(s) de R$ 50,00\n", auxCinquenta);
	printf("%d nota(s) de R$ 20,00\n", auxVinte);
	printf("%d nota(s) de R$ 10,00\n", auxDez);
	printf("%d nota(s) de R$ 5,00\n", auxCinco);
	printf("%d nota(s) de R$ 2,00\n", auxDois);
	printf("%d nota(s) de R$ 1,00\n", ntsUm);

	return 0;
}
