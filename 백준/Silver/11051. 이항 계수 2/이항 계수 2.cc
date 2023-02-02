#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int dp[1001][1001] = {0, };

    cin >> N >> K;
    
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j <= K; j++)
        {
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K] % 10007 << "\n";
    
    return 0;
}