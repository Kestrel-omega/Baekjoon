#include <iostream>
using namespace std;

int main()
{
	int arr[50][2] = { NULL }, n, temp, sum = 0;

	cin >> n;

	for (int i = 0;i < n;i++)
		cin >> arr[i][0];
	for (int i = 0;i < n;i++)
		cin >> arr[i][1];

	for(int i = 0;i<n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (arr[i][0] < arr[j][0])
			{
				temp = arr[i][0];
				arr[i][0] = arr[j][0];
				arr[j][0] = temp;
			}
		}
	}
	for(int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (arr[i][1] > arr[j][1])
			{
				temp = arr[i][1];
				arr[i][1] = arr[j][1];
				arr[j][1] = temp;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		sum += arr[i][0] * arr[i][1];
	}

	cout << sum << endl;

	return 0;
}
