#include <iostream>
using namespace std;

int euclidean(int a, int b)
{
	return a % b ? euclidean(b, a%b) : b;
}

int main()
{
	int a, b, gcd, lcm;

	cin >> a >> b;

	gcd = euclidean(a, b);
	lcm = a * b / gcd;

	cout << gcd << endl << lcm << endl;

	return 0;
}