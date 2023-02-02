#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int dp[1001][100001] = {0, };
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;

        for(int j = 1; j <= K; j++)
        {
            if(j < W) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
        }
    }

    cout << dp[N][K] << '\n';
    
    return 0;
}