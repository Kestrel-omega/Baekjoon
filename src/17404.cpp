#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans = 1048576;
int cost_RGB[1001][3];
int dp[1001][3];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++) cin >> cost_RGB[i][j];
    }

    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == k) dp[1][i] = cost_RGB[1][i];
            else dp[1][i] = 1048576;
        }

        for (int i = 2; i <= N; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost_RGB[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost_RGB[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost_RGB[i][2];
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == k) continue;
            ans = min(ans, dp[N][i]);
        }
    }

    cout << ans;

    return 0;
}