#include <stdio.h>
int main()
{
	int a = 0, i, j;
	scanf("%d", &a);
	for (i = 1; i<=a; i++)
	{
		for (j = a; j > i; j--)
			printf(" ");
		for (j = 1; j<=i; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}