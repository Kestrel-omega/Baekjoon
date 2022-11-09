#include <iostream>
using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;
    int result, year = 1;
    while (1)
    {
        if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
        {
            result = year;
            break;
        }
        year++;
    }
    cout << result << endl;
    return 0;
}