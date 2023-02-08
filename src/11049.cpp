#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, arr[501][2], dp[501][501] = {0};
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1];

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j + i <= N; j++)
        {
            dp[j][j + i] = 2147483647;
            for (int k = j; k < j + i; k++) dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + arr[j][0] * arr[k][1] * arr[j + i][1]);
        }
    }

    cout << dp[1][N];
    
    return 0;
}