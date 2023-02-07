#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K;

    cin >> T;

    while(T--)
    {
        int arr[501] = {0,};
        int sum[501] = {0,};
        int dp[501][501] = {0,};
        cin >> K;

        for(int i = 1; i <= K; i++) 
        {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= K - i; j++)
            {
                dp[j][j + i] = 2147483647;
                for (int k = j; k < j + i; k++) dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);

                // cout << "dp[" << j << "][" << j+i << "] = " << dp[j][j+i] << "\n";
            }
        }

        cout << dp[1][K] << '\n';
    }    
    return 0;
}