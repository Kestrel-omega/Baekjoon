#include <iostream>
using namespace std;

int main()
{
	int n = 0, a = 1, b = 0;

	cin >> n;

	for (a = 1 ; a <= n;a++)
	{
		b = a + b;
	}

	cout << b << endl;

	return 0;
}