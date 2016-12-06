#include <stdio.h>
#include <stdlib.h>

int main()
{
    float matriz[10][3];
    float soma[10] = {0,0,0,0,0,0,0,0,0,0}; // Iniciei todas as posições do vetor soma com zero pra nao gerar lixo
    float media[10];
    int i, j;

    for(i = 0; i<10; i++)
        for(j = 0; j<3; j++)
            scanf("%f", &matriz[i][j]);

    for(i = 0; i < 10; i++)
        for(j = 0; j < 3; j++)
        {
            soma[i] += matriz[i][j];
            media[i] = soma[i]/3;
        }

    for(i = 0; i < 10; i++)
        printf("Aluno %d, media: %f\n", i, media[i]);

    return 0;
}
