#include <stdio.h>
#include <stdlib.h>

int main()
{
	float n1 = 0.0, n2 = 0.0, n3 = 0.0, n4 = 0.0, nExame = 0.0, media = 0.0, mediaFinal = 0.0;
	scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

	media = (2*n1 + 3*n2 + 4*n3 + 1*n4)/10;
	printf("Media: %.1f\n", media);

	if(media >= 7.0)
	{
		printf("Aluno aprovado.\n");
	}
	else if(media < 5.0)
	{
		printf("Aluno reprovado.\n");
	}
	else if(media >= 5.0 && media <= 6.9)
	{
		printf("Aluno em exame.\n");
		scanf("%f", &nExame);
		printf("Nota do exame: %.1f\n", nExame);
		mediaFinal = (media + nExame) / 2;
		if(mediaFinal >= 5.0)
		{
			printf("Aluno aprovado.\n");
			printf("Media final: %.1f\n", mediaFinal);
		}
		else
		{
			printf("Aluno reprovado.\n");
			printf("Media final: %.1f\n", mediaFinal);
		}
	}

	return 0;
}
