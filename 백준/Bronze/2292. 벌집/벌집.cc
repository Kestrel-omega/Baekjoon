#include <iostream>
using namespace std;

int main() 
{
	int num = 0, data = 1, i = 1;
	cin >> num;

	if (num == 1)
	{
		cout << "1" << endl;
		return 0;
	}

	num -= 2;
	num /= 6;
	
	while (1)
	{
		if (num < data)
		{
			cout << i+1 << endl;
			break;
		}
		i++;
		data += i;
	}

	return 0;
}