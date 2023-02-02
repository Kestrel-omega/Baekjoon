#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n)
{
    int ans = 1;
    for (int i = 2; i < n + 1; i++)
        ans *= i;
    return ans;
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << factorial(N) / factorial(K) / factorial(N - K);
}