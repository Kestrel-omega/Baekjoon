#include <iostream>
using namespace std;

int main() 
{
	int input = 0, sum = 0, temp = 0;
	char num;
	
	cin >> input;
	cin.get();

	for (int i = 0;i < input;i++)
	{
		cin.get(num);
		temp = num - '0';
		sum += temp;
	}
	cout << sum << endl;
	
	return 0;
}