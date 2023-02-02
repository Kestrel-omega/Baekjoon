#include <iostream>
using namespace std;

int main() 
{
	int A = 0, B = 0, C = 0, cross = 0, num[10] = { NULL }, i = 0;

	cin >> A >> B >> C;
	cross = A * B * C;

	while (cross > 0)
	{
		i = cross % 10;
		num[i]++;
		cross /= 10;
	}

	for (i = 0;i < 10;i++)
	{
		cout << num[i] << endl;
	}

	return 0;
}