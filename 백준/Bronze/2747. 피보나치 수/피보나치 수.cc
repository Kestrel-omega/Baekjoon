#include <iostream>
using namespace std;
#define N 46

int main() 
{
	int n = 0, fib[N] = { NULL };
	
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2;i < N;i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cin >> n;
	cout << fib[n];

	return 0;
}