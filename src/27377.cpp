#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    long long int dp[1000001] = {0,};
    int T;
    cin >> T;
    while (T--)
    {
        long long int n, s, t;
        
        cin >> n >> s >> t;

        if(s < t)
        {
            cout << n*s << "\n";
            continue;
        }

        for (int i = 0; i <= t; i++) dp[i] = s*i;

        for (int i = t+1; i <= n; i++)
        {
            if(i % 2 == 0) dp[i] = min(dp[i-1] + s, dp[i/2] + t);
            else dp[i] = min(dp[i-1] + s, dp[(i+1)/2] + t + s);
        }

        cout << dp[n] << "\n";
    }
    return 0;
}

