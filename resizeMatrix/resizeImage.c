#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Prototipos das funcoes
unsigned char **matrixAlloc(int row, int col);
void matrixDealloc(unsigned char **matrix, int row, int col);
void imprimeMatriz(unsigned char **matrix, int row, int col);

int main(int argc, char **argv)
{
	//  Nome do arquivo digitado na linha de comando
	FILE *file = fopen(*(argv + 1), "rb");

	if (!file)
	{
		printf("File not found!\n");
		exit(1);
	}
	else
	{
		//  Pra entrar nesse else o nome da imagem tem que ser digitado corretamente na linha de comando
		unsigned char buffer = 0;
		//  Descarta o header desnecessario do arquivo pgm
		while(getc(file) != '\n');
      	while(getc(file) == '#');
    	while(getc(file) != '\n');

		int row  = 0;
		int col = 0;
		int valueLuminance = 0;

		//  Leitura do header necessario da imagem como altura, largura e valor maximo de cor (luminancia).
		fscanf(file, "%d", &row);
		fscanf(file, "%d", &col);
		fscanf(file, "%d", &valueLuminance);

		//  Alocacao da matriz de bytes da imagem
		unsigned char **matrix = matrixAlloc(row, col);
		getc(file);

		//  Leitura da imagem PGM
		//  Passando cada pixel da imagem para a matriz
		int i, j;
		for (i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				buffer = getc(file);
				matrix[i][j] = buffer;
			}
		}
			
		// get vector X
		int vetorX[16], pixelX = 0;
		for (i = 0; i < row; i = i + 73)
			for (j = 0; j < col; j = j + 73) 
			{
				vetorX[pixelX] = matrix[i][j];
				pixelX++;
			}

		for(i=0; i < pixelX; i++)
			printf("\n%d ", vetorX[i]);

		// get vector Y
		int vetorY[16], pixelY = 0;
		for (i = 0; i < row; i = i + 5)
			for (j = 0; j < col; j = j + 5) 
			{
				vetorY[pixelY] = matrix[i][j];
				pixelY++;
			}
		printf("\n\n");
		for(i=0; i < pixelY; i++)
			printf("\n%d ", vetorY[i]);

		// get matrix decimization
		//int matrixDeci[2][2];
		unsigned char **matrixDeci = matrixAlloc(8, 8);
		for (i = 0; i < pixelX; i++)
		{
			matrixDeci[i/row][i%col] = vetorX[i];
		}
	

		printf("\n\n");
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				printf("%d	", matrixDeci[i][j]);
			}
			printf("\n");
		}

		fclose(file);
		matrixDealloc(matrix, row, row);
		
	}

	if (argc != 2){
		printf("O nome do arquivo nao foi passado na linha de comando!\n");
		exit(1);
	}

	return 0;
}

unsigned char **matrixAlloc(int row, int col)
{
    /* Se houver memoria disponivel, esta funcao, aloca uma matriz com L linhas (row) e C colunas (col)
    e devolve o endereço-base da matriz; Caso contrário, devolve um ponteiro nulo */

    unsigned char **matrix = malloc(sizeof(unsigned char*) * row);

    if(matrix == NULL) //  Memória insuficiente
    {
        return NULL; //  Ponteiro NULL é um ponteiro zero (nao aponta pra nada)
    }
    unsigned int i, j;
    for(i = 0; i < row; i++)
    {
        matrix[i] = malloc(sizeof(unsigned char*) * col);
        if(matrix[i] == NULL)
        {
            for(j = 0; j < i; j++)
            {
                free(matrix[j]);
            }
        free(matrix);
        return NULL;
        }
    }
    return matrix;
}

void matrixDealloc(unsigned char **matrix, int width, int height)
{
	 //  Desaloca uma matriz dinamicamente alocada com malloc
    if(matrix != NULL)
    {
        int i;
        for(i = 0; i < height; i++)
        {
            if (matrix[i] != NULL)
            {
                free(matrix[i]);
            }
        }
        free(matrix);
    }
}

void imprimeMatriz(unsigned char **matrix, int row, int col)
{
	int i, j;
	printf(" (");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("%d		", matrix[i][j]);
		}
		printf(")\n");
	}
}
