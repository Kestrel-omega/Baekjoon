#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int num=0, a, b;

	cin >> num;

	for (a = 0; a<num; a++)
	{
		for (b = num; b>a; b--)
			printf("*");
		printf("\n");
	}
    
	return 0;
}