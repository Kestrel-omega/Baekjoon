#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 2147483647

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int current = pq.top().second;
        int current_dist = -pq.top().first;
        pq.pop();

        if(dist[current] < current_dist) continue;

        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int next_dist = current_dist + graph[current][i].second;

            if(dist[next] > next_dist)
            {
                dist[next] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    while(E--)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    for(int i = 1; i <= V; i++) dist[i] = INF;

    dijkstra(K);

    for(int i = 1; i <= V; i++)
    {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}