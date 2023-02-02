#include <iostream>
using namespace std;

int main() 
{
	int a = 0, b = 0, c = 0;

	cin >> a >> b >> c;
	
	if ((a<=b&&a>=c) || (a<=c&&a>=b))
		cout << a << endl;
	else if ((b<=c&&b>=a) || (b<=a&&b>=c))
		cout << b << endl;
	else if ((c<=a&&c>=b) || (c<=b&&c>=a))
		cout << c << endl;

	return 0;
}