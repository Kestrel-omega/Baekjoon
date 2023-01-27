#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int P[1001] = {0,};
    int dp[1001] = {0,};
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> P[i];

    for(int i = 1; i <= N; i++)
    {
        dp[i] = P[i];
        for(int j = 1; j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j] + P[j]);
        }
    }
    cout << dp[N] << '\n';
    
    return 0;
}