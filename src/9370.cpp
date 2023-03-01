#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 16777216;

vector<pair<int, int>> graph[2001];

void dijkstra(int start, int dist[])
{
    priority_queue<pair<int, int>> node;
    node.push({0, start});
    dist[start] = 0;

    while(!node.empty())
    {
        int cost = -node.top().first;
        int current = node.top().second;
        node.pop();

        if(dist[current] < cost) continue;

        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int next_cost = cost + graph[current][i].second;

            if(dist[next] > next_cost)
            {
                dist[next] = next_cost;
                node.push({-next_cost, next});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, m, t, s, g, h, a, b, d;
    int dist_s[2001];
    int dist_g[2001];
    int dist_h[2001];

    cin >> T;
    while(T--)
    {
        vector<int> result;

        cin >> n >> m >> t >> s >> g >> h;

        for(int i = 0; i < 2001; i++) 
        {
            graph[i].clear();
            dist_s[i] = MAX;
            dist_g[i] = MAX;
            dist_h[i] = MAX;
        }

        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }

        for(int i = 0; i < t; i++)
        {
            cin >> a;
            result.push_back(a);
        }

        sort(result.begin(), result.end());

        dijkstra(s, dist_s);
        dijkstra(g, dist_g);
        dijkstra(h, dist_h);

        for(int i = 0; i < t; i++)
        {
            int temp = result[i];
            if(dist_s[temp] == dist_s[g] + dist_g[h] + dist_h[temp] || dist_s[temp] == dist_s[h] + dist_h[g] + dist_g[temp]) cout << temp << " ";
        }

        cout << "\n";
    }
    
    return 0;
}