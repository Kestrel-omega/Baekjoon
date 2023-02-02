#include <iostream>
using namespace std;

int main() 
{
	int n = 0;

	cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < i;j++)
			cout << " ";
		for (int k = 0;k < (2 * (n-i) - 1);k++)
			cout << "*";
		cout << endl;
	}

	return 0;
}