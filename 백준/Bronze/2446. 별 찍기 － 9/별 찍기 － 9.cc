#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < i;j++)
			cout << " ";
		for (int j = 0;j < 2*(n - i)-1;j++)
			cout << "*";
		cout << endl;
	}
	for (int i = n-2;i > -1;i--)
	{
		for (int j = 0;j < i;j++)
			cout << " ";
		for (int j = 0;j < 2 * (n - i) - 1;j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}