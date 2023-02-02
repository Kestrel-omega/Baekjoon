#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int j = 0; j < T; j++) 
    {
        long double x, y, d, i = 1;
        cin >> x >> y;
        d = y - x;

        while (1)
        {
            if (i * i > d)
                break;
            i++;
        }

        if (pow(i - 1, 2) == y - x)
            cout << 2 * i - 3 << '\n';
        else if ((pow(i, 2) + pow(i - 1, 2)) / 2 >= y - x)
            cout << 2 * (i - 1) << '\n';
        else
            cout << 2 * (i - 1) + 1 << '\n';
    }
}