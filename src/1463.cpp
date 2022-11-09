#include <iostream>

using namespace std;

int d[1000001];

int main()
{
    int t;
    cin >> t;
    d[1] = 0;
    
    for (int i = 2; i <= t; i++)
    {
        d[i] = d[i - 1] + 1;

        if (i % 2 == 0 && d[i] > d[i / 2] + 1)
            d[i] = d[i / 2] + 1;
        if (i % 3 == 0 && d[i] > d[i / 3] + 1)
            d[i] = d[i / 3] + 1;
    }

    cout << d[t] << '\n';

    return 0;
}
