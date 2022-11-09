#include <iostream>
#include <math.h>

using namespace std;

#define SIZE 10000

int main()
{
	int arr[SIZE] = { 0, };
	int temp = (int)sqrt(SIZE);
	for (int i = 2; i <= temp; i++)
	{
		for (int j = i*i; j <= SIZE; j += i)
		{
			if (arr[j] % i == 0)
				arr[j] = 1;
		}
	}
	int cycle, num;
	cin >> cycle;
	for (int k = 0; k < cycle; k++)
	{
		cin >> num;
		for (int l = num / 2; l > 0; l--)
		{
			if (arr[l] != 1 && arr[num - l] != 1)
			{
				cout << l << num - l << endl;
				break;
			}
		}
	}
	return 0;
}
