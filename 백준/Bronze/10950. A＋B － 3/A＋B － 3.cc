#include <iostream>
using namespace std;

int main()
{
	int i = 0, A = 0, B = 0;

	cin >> i;
	
	for (int a = i;a > 0;a--)
	{
		cin >> A >> B;
		cout << A + B << endl;
	}

	return 0;
}