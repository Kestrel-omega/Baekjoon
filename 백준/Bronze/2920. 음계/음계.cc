#include <iostream>
using namespace std;

int main() 
{
	int str[8];

	for (int i = 0;i < 8;i++)
		cin >> str[i];

	if (str[0] < str[1] && str[1] < str[2] && str[2] < str[3] && str[3] < str[4] && str[4] < str[5] && str[5] < str[6] && str[6] < str[7])
		cout << "ascending\n";
	else if (str[0] > str[1] && str[1] > str[2] && str[2] > str[3] && str[3] > str[4] && str[4] > str[5] && str[5] > str[6] && str[6] > str[7])
		cout << "descending\n";
	else
		cout << "mixed\n";

	return 0;
}