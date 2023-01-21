#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int B_arr[2001][2001] = {0,};
    int W_arr[2001][2001] = {0,};
    int B_dp[2001][2001] = {0,};
    int W_dp[2001][2001] = {0,};
    int N, M, K;
    int answer = 2000001;
    char c;

    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> c;
            if ((i + j) % 2 == 0)
            {
                if (c == 'B')
                {
                    W_arr[i][j] = 1;
                    B_arr[i][j] = 0;
                }
                else
                {
                    B_arr[i][j] = 1;
                    W_arr[i][j] = 0;
                }
            }
            else
            {
                if (c == 'B')
                {
                    B_arr[i][j] = 1;
                    W_arr[i][j] = 0;
                }
                else 
                {
                    W_arr[i][j] = 1;
                    B_arr[i][j] = 0;
                }
            }
            
            B_dp[i][j] = B_dp[i - 1][j] + B_dp[i][j - 1] - B_dp[i - 1][j - 1] + B_arr[i][j];
            W_dp[i][j] = W_dp[i - 1][j] + W_dp[i][j - 1] - W_dp[i - 1][j - 1] + W_arr[i][j];
        }
    }
    
    for (int i = 0; i <= N - K; i++)
    {
        for (int j = 0; j <= M - K; j++)
        {
            answer = min(B_dp[i + K][j + K] - B_dp[i][j + K] - B_dp[i + K][j] + B_dp[i][j], answer);
            answer = min(W_dp[i + K][j + K] - W_dp[i][j + K] - W_dp[i + K][j] + W_dp[i][j], answer);
        }
    }
    cout << answer << endl;

    return 0;
}