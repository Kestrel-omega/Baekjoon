#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int coin[101];
    int dp[10001] = {0,};
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> coin[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= k; j++) dp[j] += dp[j - coin[i]];
    }

    cout << dp[k] << '\n';
    
    return 0;
}