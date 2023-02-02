#include <iostream>
using namespace std;

int main() 
{
	int data[1000];

	int i, j, temp, num;

	cin >> num;

	for (i = 0; i < num; i++)
		cin >> data[i];

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < num; i++)
		cout << data[i] << endl;

	return 0;
}