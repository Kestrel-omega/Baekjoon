#include <iostream>
#include <math.h>

using namespace std;

#define SIZE 123456*2+1

int main()
{
	int arr[SIZE] = { 0, };
	for (int i = 2; i < SIZE * 2; i++)
		arr[i] = i;
	int temp = (int)sqrt(SIZE);
	for (int j = 2; j <= temp; j++)
	{
		if (arr[j] == 0)
			continue;
		else
		{
			for (int k = j + 1; k <= SIZE; k++)
			{
				if (arr[k] == 0)
					continue;
				if (arr[k] % j == 0)
					arr[k] = 0;
			}			
		}
	}
	int num;
	while (1)
	{
		cin >> num;
		if (num == 0)
			break;
		int count = 0;
		for (int l = num + 1; l <= 2 * num; l++)
		{
			if (arr[l] != 0)
				count++;
		}
			
		cout << count << endl;
	}
	return 0;
}
