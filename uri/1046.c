#include <stdio.h>
#include <stdlib.h>

int main()
{
	int horaInicio = 0, horaFim = 0, totalTempo = 0;
	scanf("%d %d", &horaInicio, &horaFim);
	
	if(horaInicio == horaFim)
	{
		totalTempo = ((horaInicio - horaFim) + 24);
		printf("O JOGO DUROU %d HORA(S)\n", totalTempo);
	}
	else
	{
		if(horaInicio > horaFim)
		{
			totalTempo = ((24 - horaInicio) + (horaFim - 0));
			printf("O JOGO DUROU %d HORA(S)\n", totalTempo);
		}
		if(horaInicio < horaFim)
		{
			totalTempo = (horaFim - horaInicio);
			printf("O JOGO DUROU %d HORA(S)\n", totalTempo);
		}
	}

	return 0;
}
