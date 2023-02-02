#include <iostream>

using namespace std;

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    if (B >= C)
    {
        cout << "-1";
        return 0;
    }

    cout << A / (C - B) + 1;
    return 0;
}