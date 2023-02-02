#include <iostream>
using namespace std;

int main() 
{
	int num[5], point, car = 0;

	cin >> point;
	for (int i = 0;i < 5;i++)
	{
		cin >> num[i];

		if (num[i] == point)
			car++;
	}
	cout << car<< endl;

	return 0;
}