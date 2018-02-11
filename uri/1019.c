#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N = 0, tempoHora = 0, auxHora = 0, tempoMin = 0, auxMin = 0, tempoSeg = 0;
	scanf("%d", &N);
	/* converte seg pra hora  */
	tempoHora = N / 3600;
	auxHora = tempoHora * 3600;
	/* converte seg pra min  */
	tempoMin = ((N - auxHora) / 60);
	auxMin = tempoMin * 60;
	/* parte dos segundos restantes */
	tempoSeg = ((N - auxHora) - auxMin);

	printf("%d:%d:%d\n", tempoHora, tempoMin, tempoSeg);

	return 0;
}
