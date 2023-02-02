#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    long long int dp[101] = {0, };
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for (int i = 6; i <= 100; i++) dp[i] = dp[i - 1] + dp[i - 5];
    cin >> T;

    while(T--)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }
    
    return 0;
}