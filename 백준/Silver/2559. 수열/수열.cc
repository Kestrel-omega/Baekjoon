#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K;
    int answer = -100000001;
    int sum[100001] = { 0, };
    cin >> T >> K;

    for (int i = 1; i <= T; i++)
    {
        int temp;
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for (int i = K; i <= T; i++)
        answer = max(answer, sum[i] - sum[i - K]);

    cout << answer;

    return 0;
}