#include <iostream>
using namespace std;
int num[10000];
int main()
{
	int n = 0, x = 0;
	cin >> n >> x;
	for (int i = 0;i < n;i++)
		cin >> num[i];
	for (int i = 0;i < n;i++)
	{
		if (num[i] < x)
			cout << num[i] << " ";
	}
    
	return 0;
}