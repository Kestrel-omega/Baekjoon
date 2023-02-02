#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int start, int to, int end)
{
    if (n == 1)
        cout << start << " " << end << "\n";
    else
    {
        hanoi(n - 1, start, end, to);
        cout << start << " " << end << "\n";
        hanoi(n - 1, to, start, end);
    }
}

int main()
{
    int N, count;
    cin >> N;

    count = pow(2, N) - 1;
    cout << count << "\n";
    hanoi(N, 1, 2, 3);

    return 0;
}