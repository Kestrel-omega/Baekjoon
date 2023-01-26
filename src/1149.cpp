#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, G, B;
    int dp[1001][3] = {0, };
    cin >> N;

    cin >> R >> G >> B;

    dp[1][0] = R;
    dp[1][1] = G;
    dp[1][2] = B;

    for (int i = 2; i <= N; i++)
    {
        cin >> R >> G >> B;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
    }

    cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << '\n';

    return 0;
}