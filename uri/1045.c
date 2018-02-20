#include <stdio.h>
#include <stdlib.h>

int main()
{
	double a = 0.0, b = 0.0, c = 0.0, aux = 0.0;
	scanf("%lf %lf %lf", &a ,&b ,&c);

	if(((a > b) && (a > c)) && (b > c))
	{
		a = a;
		b = b;
		c = c;
	}
	if(((a > b) && (a > c)) && (c > b))
   {
      a = a;
		aux = b;
		b = c;
		c = aux;	
	}
	if(((b > a) && (b > c)) && (a > c))
	{
		aux = a;
		a = b;
		b = aux;
		c = c;
	}
	if(((b > a) && (b > c)) && (c > a))
   {
		aux = a;
		a = b;
		b = c;
		c = aux;
   }
	if(((c > b) && (c > a)) && (b > a))
   {
		aux = a;
		a = c;
		b = b;
		c = aux;
	}
	if(((c > b) && (c > a)) && (a > b))
   {
		aux = a;
		a = c;
		c = b;
		b = aux;
	}
	if((a == c) || (a == b) || (b == c))
	{
		a = a;
		b = b;
		c = c;
	}
	if((a == b) && (a!=c))
	{
		if(c > a)
		{
			aux = a;
			a = c;
			c = aux;
			b = b;
		}
		else
		{
			a = a;
			b = b;
			c = c;
		}
	}
	if(b==c && b!=a)
	{
		if(b > a)
		{
			aux = a;
			a = b;
			b = aux;
			c = c;
		}
		else
		{
			a = a;
			b = b;
			c = c;
		}
	}
	if(a==c && a!=b)
	{
		if(b > a)
		{
			aux = a;
			a = b;
			b = aux;
			c = c;
		}
		else
		{
			a = a;
			b = b;
			c = c;
		}
	}

	if((a > 0) && (b > 0) && (c > 0))
	{	
		if((a > b+c) || (a == b+c))
		{
			printf("NAO FORMA TRIANGULO\n");
		}
		else
		{
			if((a*a) == ((b*b) + (c*c)))
			{
				printf("TRIANGULO RETANGULO\n");
			}
			if((a*a) > ((b*b) + (c*c)))
			{
				printf("TRIANGULO OBTUSANGULO\n");
			}
			if((a*a) < ((b*b) + (c*c)))
			{
				printf("TRIANGULO ACUTANGULO\n");
			}
			if((a == b) && (a == c) && (b == c))
			{
				printf("TRIANGULO EQUILATERO\n");
			}
			if(a==b && a!=c || b==c && b!=a || a==c && a!=b)
			{
				printf("TRIANGULO ISOSCELES\n");
			}
		}
	}

	return 0;
}
