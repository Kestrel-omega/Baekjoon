#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, sum = 0;
    int memory[101] = { 0 };
    int cost[101] = { 0 };
    int dp[101][10001] = { 0 };

    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> memory[i];

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (cost[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[N][i] >= M)
        {
            cout << i;
            break;
        }
    }

    return 0;
}