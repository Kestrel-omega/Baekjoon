#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max_num = 0;
    int triangle[501][501] = {0, };
    int dp[501][501] = {0, };

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++) cin >> triangle[i][j];
    }

    dp[1][1] = triangle[1][1];

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    for(int i = 1; i <= n; i++) if(max_num < dp[n][i]) max_num = dp[n][i];

    cout << max_num << '\n';
    
    return 0;
}