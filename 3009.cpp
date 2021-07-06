#include <iostream>

using namespace std;


int main()
{
	int x, y, ax, ay, bx, by, cx, cy;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;

	if (ax == bx)
		x = cx;
	else if (ax == cx)
		x = bx;
	else
		x = ax;

	if (ay == by)
		y = cy;
	else if (ay == cy)
		y = by;
	else
		y = ay;

	cout << x << " " << y << endl;

	return 0;
}
