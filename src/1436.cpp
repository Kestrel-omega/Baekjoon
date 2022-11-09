#include <iostream>

using namespace std;

int main()
{
    int N;
    int title = 665;
    int number = 0;

    cin >> N;

    while (N - number)
    {
        title++;
        int temp = title;
        while (temp > 100)
        {
            if (temp % 1000 == 666)
            {
                number++;
                break;
            }
            else temp /= 10;
        }
    }

    cout << title;

    return 0;
}