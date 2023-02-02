#include <iostream>
using namespace std;

int cycle(int i)
{
	int a = i / 10;
	int b = i % 10;
	int c = (a + b) % 10;

	return (10 * b + c);
}

int main()
{
	int num = 0, newNum, i = 1;
	cin >> num;
	newNum = cycle(num);

	while (!(num == newNum))
	{
		newNum = cycle(newNum);
		i++;
	}

	cout << i << endl;

	return 0;
}

