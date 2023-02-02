#include <iostream>
using namespace std;

int main() 
{
	int N = 0, sum = 0;
	
	cin >> N;

	switch (N)
	{
	case 4:
	case 7:
		sum = -1;
		break;
	case 3:
	case 5:
		sum = 1;
		break;
	case 6:
	case 8:
		sum = 2;
		break;
	case 9:
		sum = 3;
		break;
	default:
		if (N % 5 == 0)
		{
			sum = N / 5;
		}
		else if ((N % 5 == 1) || (N % 5 == 3))
		{
			sum = N / 5 + 1;
		}
		else if ((N % 5 == 2) || (N % 5 == 4))
		{
			sum = N / 5 + 2;
		}
		break;
	}
	cout << sum << endl;

	return 0;
}