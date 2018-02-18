#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a = 0.0, b = 0.0, c = 0.0;
	scanf("%f %f %f", &a, &b, &c);

	if(abs(b-c) < a && a < (b+c))
	{
		printf("Perimetro = %.1f\n", a+b+c);
	}
	else if(abs(a-c) < b && b < (a+c))
	{
		printf("Perimetro = %.1f\n", a+b+c);
	}
	else if(abs(a-b) < c && c < (a+b))
	{
		printf("Perimetro = %.1f\n", a+b+c);
	}
	else
	{
		printf("Area = %.1f\n", (a+b)*c/2);
	}

	return 0;
}
