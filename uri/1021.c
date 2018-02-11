#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n100 = 0,n20 = 0,n50 = 0,n10 = 0,n5 = 0,n2 = 0,v = 0;
	int m1 = 0,m50 = 0,m25 = 0,m10 = 0,m5 = 0,m01 = 0,t = 0;
	double valor = 0.0 ,x = 0.0;
	scanf("%lf", &valor);

	if(0 <= valor <= 1000000.00)
	{
		v=(int)valor;

		n100=(v/100);
		n50=((v%100)/50);
		n20=(((v%100)%50)/20);
		n10=((((v%100)%50)%20)/10);
		n5=(((((v%100)%50)%20)%10)/5);
		n2=((((((v%100)%50)%20)%10)%5)/2);
		m1=(((((((v%100)%50)%20)%10)%5)%2)/1);

		x=valor-v;
		t=x*100;

		m50=(t/50);
		m25=((t%50)/25);
		m10=(((t%50)%25)/10);
		m5=((((t%50)%25)%10)/5);
		m01=(((((t%50)%25)%10)%5)/1);

		printf("NOTAS:\n");
		printf("%d nota(s) de R$ 100.00\n", n100);
		printf("%d nota(s) de R$ 50.00\n",  n50);
		printf("%d nota(s) de R$ 20.00\n",  n20);
		printf("%d nota(s) de R$ 10.00\n",  n10);
		printf("%d nota(s) de R$ 5.00\n",   n5);
		printf("%d nota(s) de R$ 2.00\n",   n2);
		printf("MOEDAS:\n");
		printf("%d moeda(s) de R$ 1.00\n", m1);
		printf("%d moeda(s) de R$ 0.50\n", m50);
		printf("%d moeda(s) de R$ 0.25\n", m25);
		printf("%d moeda(s) de R$ 0.10\n", m10);
		printf("%d moeda(s) de R$ 0.05\n", m5);
		printf("%d moeda(s) de R$ 0.01\n", m01);
	}
	return 0;
}
