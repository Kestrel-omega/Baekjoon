#include <iostream>
using namespace std;

int main() 
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e;

	f = (a*a + b * b + c * c + d * d + e * e) % 10;

	cout << f << endl;
	return 0;
}