#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
const int INF = 2147483647;
vector<int> graph[21];
vector<int> dp;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cost;
            cin >> cost;
            graph[i].push_back(cost);
        }
    }
    for (int i = 0; i < pow(2, N); i++) dp.push_back(INF);

    dp[0] = 0;

    for (int i = 0; i < pow(2, N); i++)
    {
        int count = 0;
        int temp = i;
        
        while(temp)
        {
            count += temp & 1;
            temp >>= 1;
        }

        for (int j = 0; j < N; j++)
        {
            if (! (i & (1 << j))) dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + graph[count][j]);
        }
    }

    cout << dp.back() << endl;

    return 0;
}
