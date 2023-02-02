#include <iostream>
using namespace std;

int main() 
{
	int a = 0, b = 0, c = 0, sum = 0;
	scanf("%d",&c);
	for (c;c > 0;c--)
	{
		scanf("%d %d", &a,&b);
		printf("%d\n", a + b);
	}

	return 0;
}