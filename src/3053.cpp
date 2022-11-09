#include <iostream>

#define PI 3.14159265358979323846

using namespace std;

int main()
{
	float R;
	cin >> R;
	cout.precision(15);
	cout << PI * R * R << endl;
	cout << 2.0 * R * R << endl;
	return 0;
}
