#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int dp[31][31] = {0,};
    int T, N, M;

    for(int i = 1; i < 31; i++)
    {
        dp[1][i] = i;
        dp[i][i] = 1;
    }

    cin >> T;

    while(T--)
    {
        cin >> N >> M;

        if(dp[N][M] == 0)
        {
            for(int i = 2; i <= N; i++)
            {
                for(int j = i + 1; j <= M; j++)
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
            }
        }
        
        cout << dp[N][M] << "\n";
    }
    
    return 0;
}