#include <iostream>
using namespace std;

int main() 
{
	int x = 0, sum = 0;
	cin >> x;
	while (!(x == 0))
	{
		sum = sum + x % 2;
		x /= 2;
	}

	cout << sum << endl;

	return 0;
}