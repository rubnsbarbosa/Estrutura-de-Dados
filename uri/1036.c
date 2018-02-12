#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a = 0.0, b = 0.0, c = 0.0, x1 = 0.0, x2 = 0.0, delta = 0.0;
	scanf("%lf %lf %lf", &a, &b, &c);

	delta = b*b - 4*a*c;
	x1 = (-b + sqrt(delta)) / (2*a);
	x2 = (-b - sqrt(delta)) / (2*a);

	if((2*a == 0) || (delta < 0))
	{
		printf("Impossivel calcular\n");
	}
	else
	{
		printf("R1 = %.5lf\n", x1);
		printf("R2 = %.5lf\n", x2);
	}

	return 0;
}
