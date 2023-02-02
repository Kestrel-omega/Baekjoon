#include <iostream>
using namespace std;

int main() 
{
	int n = 0, num[1000], max = 0, sum = 0;
	double avg = 0;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> num[i];
		if (num[i] > max)
			max = num[i];
		sum += num[i];
	}
	avg = (double)sum / (double)max * 100 / (double)n;

	cout << avg << endl;

	return 0;
}