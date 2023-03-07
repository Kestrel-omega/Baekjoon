#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sequence;
int dp[1000001] = {0, };

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[N] << "\n" << N << " ";

    while (N != 1)
    {
        if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
        {
            cout << N / 3 << " ";
            N /= 3;
        }
        else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
        {
            cout << N / 2 << " ";
            N /= 2;
        }
        else
        {
            cout << N - 1 << " ";
            N -= 1;
        }
    }
    
    return 0;
}