#include <stdio.h>
#define PI 3.14159

int main()
{
	float area = 0.0, raio = 0.0;	
	
	printf("Digite o raio: ");
	scanf("%f", &raio);
	
	area = (raio * raio) * PI;

	printf("A = %.4f\n", area);
	return 0;
}
