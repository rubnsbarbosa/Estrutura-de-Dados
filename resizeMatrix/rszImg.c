#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 3;
	int col = 8;
/*
	int matriz [10][10] = { 
						 {92,    99,     1,     8,    15,    67,    74,    51,    58,    40},
						 {98,    80,     7,    14,    16,    73,    55,    57,    64,    41},
						 {4,    81,    88,    20,    22,    54,    56,    63,    70,    47},
						 {85,    87,    19,    21,     3,    60,    62,    69,    71,    28},
						 {86,    93,    25,     2,     9,    61,    68,    75,    52,    34},
					     {17,    24,    76,    83,    90,    42,    49,    26,    33,    65},
						 {23,     5,    82,    89,    91,    48,    30,    32,    39,    66},
						 {79,     6,    13,    95,    97,    29,    31,    38,    45,    72},
						 {10,    12,    94,    96,    78,    35,    37,    44,    46,    53},
						 {11,    18,   100,    77,    84,    36,    43,    50,    27,    59}
                    };
*/
	int matriz [3][8] = {
		{1,   2,   3,   4,   5,   6,   7,   8},
   		{8,   7,   6,   5,   4,   3,  2,   1},
   		{2,   3,   4,   5,   6,   7,   8,   9}
	};

	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("%d	", matriz[i][j]);
		}
		printf("\n");
	}
	
	// codigo celso/glauber
	int matrizdeci[2][4], k = 0, l = 0;
	for(i=0,j=0;i<row;i+=2,j++){
        for(k=0,l=0;k<col;k += 2,l++){
            matrizdeci[j][l] = matriz[i][k];
        }
    }


	// get vector X
/*
	int vetorX[8], pixelX = 0;
	for (i = 0; i < row; i = i + 2)
		for (j = 0; j < col; j = j + 2) 
		{
			vetorX[pixelX] = matriz[i][j];
			pixelX++;
		}
	
	for(i=0; i < pixelX; i++)
		printf("\n%d ", vetorX[i]);

*/

	// get matrix decimization
/*
	int matrixDeci[2][4];
	for (i = 0; i < pixelX; i++)
	{
		matrixDeci[i/col][i%col] = vetorX[i];
	}
*/		

	printf("\n\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d	", matrizdeci[i][j]);
		}
		printf("\n");
	}

	return 0;
}

