#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int dp[1001][1001] = {0, };
    for (int i = 1; i <= N; i++)
    {
        dp[i][1] = i;
        dp[i][0] = 1;
    }

    for (int i = 3; i <= N; i++)
    {
        for (int j = 2; j <= K; j++) dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
    }

    cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % 1000000003;

    return 0;
}