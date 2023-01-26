#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> line;
    vector<int> dp;
    int N;
    int connected_line = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int src, dst;
        cin >> src >> dst;
        line.push_back(make_pair(src, dst));
        dp.push_back(1);
    }

    sort(line.begin(), line.end());

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(line[i].second > line[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    sort(dp.begin(), dp.end());

    cout << N - dp[N-1] << "\n";

    return 0;
}