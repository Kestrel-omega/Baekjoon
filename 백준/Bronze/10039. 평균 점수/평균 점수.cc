#include <iostream>
using namespace std;

int main() 
{
	int score[5] = { NULL }, sum = 0;

	for (int a = 0; a < 5;a++)
	{
		cin >> score[a];
		if (score[a] < 40)
			score[a] = 40;
		sum = sum + score[a];
	}
	cout << sum / 5 << endl;

	return 0;
}