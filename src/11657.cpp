#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 2147483647

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    long long dist[501];
    vector<pair<int, int>> city[501];
    bool cycle = false;

    cin >> N >> M;

    while(M--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        city[a].push_back({b, c});
    }

    for(int i = 2; i <= N; i++) dist[i] = MAX;

    dist[1] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 0; k < city[j].size(); k++)
            {
                int next = city[j][k].first;
                int next_cost = city[j][k].second;

                if(dist[j] != MAX && dist[next] > dist[j] + next_cost)
                {
                    dist[next] = dist[j] + next_cost;
                    if(i == N) cycle = true;
                }
            }
        }
    }

    if(cycle) cout << "-1\n";
    else
    {
        for(int i = 2; i <= N; i++)
        {
            if(dist[i] == MAX) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }
    
    return 0;
}