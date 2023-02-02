#include <iostream>

using namespace std;

int main()
{
    int n, num = 0;
    cin >> n;

    while (n > 0)
    {
        num++;
        n -= num;
    }

    if (num % 2 == 0)
       cout << num + n << "/" << 1 + (-n);
    else
       cout << 1 + (-n) << "/" << num + n;

    return 0;
}
