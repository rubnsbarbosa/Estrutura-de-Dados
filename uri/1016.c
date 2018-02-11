#include <stdio.h>
#include <stdlib.h>

int main()
{
	int distanciaCarroX = 0, tempoCarroX = 0;
	scanf("%d", &distanciaCarroX);
	/* O carro Y se afasta 1km a cada 2 min  */
	tempoCarroX = (distanciaCarroX * 2);

	printf("%d minutos\n", tempoCarroX);

	return 0;
}
