#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1 = 0, n2 = 0, n3 = 0;
	scanf("%d %d %d", &n1, &n2, &n3);

	if(((n1 > n2) && (n1 > n3)) && (n2 > n3))
	{
		printf("%d\n%d\n%d\n", n3, n2, n1);
		printf("\n%d\n%d\n%d\n", n1, n2, n3);
	}
	else if(((n1 > n2) && (n1 > n3)) && (n3 > n2))
        {
                printf("%d\n%d\n%d\n", n2, n3, n1);
                printf("\n%d\n%d\n%d\n", n1, n2, n3);

        }
	else if(((n2 > n1) && (n2 > n3)) && (n1 > n3))
	{
		printf("%d\n%d\n%d\n", n3, n1, n2);
                printf("\n%d\n%d\n%d\n", n1, n2, n3);

	}
	else if(((n2 > n1) && (n2 > n3)) && (n3 > n1))
        {
                printf("%d\n%d\n%d\n", n1, n3, n2);
                printf("\n%d\n%d\n%d\n", n1, n2, n3);

        }
	else if(((n3 > n2) && (n3 > n1)) && (n2 > n1))
        {
                printf("%d\n%d\n%d\n", n1, n2, n3);
                printf("\n%d\n%d\n%d\n", n1, n2, n3);

        }
	else if(((n3 > n2) && (n3 > n1)) && (n1 > n2))
        {
                printf("%d\n%d\n%d\n", n2, n1, n3);
                printf("\n%d\n%d\n%d\n", n1, n2, n3);

        }

	return 0;
}
