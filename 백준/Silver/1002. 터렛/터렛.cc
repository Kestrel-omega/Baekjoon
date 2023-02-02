#include <iostream>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;

    for (int i = 0;i < T;i++)
    {
        int point = 0;
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long long dx = x1 - x2;
        long long dy = y1 - y2;

        if (r2 > r1) swap(r1, r2);
        long long plus = r1 + r2;
        long long minus = r1 - r2;
        long long r = dx * dx + dy * dy;
        plus = plus * plus;
        minus = minus * minus;

        if (plus > r && r > minus) point = 2;
        else if ((plus == r) || (minus == r && r != 0)) point = 1;
        else if ((r < minus) || (r > plus)) point = 0;
        else if ((r == 0) || (r1 == r2)) point = -1;

        cout << point << endl;
    }
    return 0;
}