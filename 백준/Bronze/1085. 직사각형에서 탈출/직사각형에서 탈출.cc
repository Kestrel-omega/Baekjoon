#include <iostream>

using namespace std;


int main()
{
	int x, y, w, h, xw, yh;
	cin >> x >> y >> w >> h;

	if (x * 2 > w)
		xw = w - x;
	else
		xw = x;
	if (y * 2 > h)
		yh = h - y;
	else
		yh = y;
	if (xw > yh)
		cout << yh << endl;
	else
		cout << xw << endl;

	return 0;
}
