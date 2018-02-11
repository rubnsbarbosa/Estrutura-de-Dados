#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tempoGastoViagem = 0, velocidadeMediaViagem = 0;
	double distanciaPercorrida = 0.0;
	double qtdeLitros = 0.0;
	scanf("%d", &tempoGastoViagem);
	scanf("%d", &velocidadeMediaViagem);

	distanciaPercorrida = (velocidadeMediaViagem * tempoGastoViagem);
	qtdeLitros = (distanciaPercorrida / 12);

	printf("%.3lf\n", qtdeLitros);

	return 0;
}
