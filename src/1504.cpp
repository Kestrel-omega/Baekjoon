#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 16777216

int N, E, essential[2], result = 0;
vector<pair<int, int>> graph[801];
int dist[801];

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

    cin >> N >> E;

    while(E--)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    cin >> essential[0] >> essential[1];

    int result_case_1 = 0;
    int result_case_2 = 0;

    for(int i = 1; i <= N; i++) dist[i] = INF;
    dijkstra(1);
    result_case_1 += dist[essential[0]];
    result_case_2 += dist[essential[1]];

    for(int i = 1; i <= N; i++) dist[i] = INF;
    dijkstra(essential[0]);
    result_case_1 += dist[essential[1]];
    result_case_2 += dist[N];

    for(int i = 1; i <= N; i++) dist[i] = INF;
    dijkstra(essential[1]);
    result_case_1 += dist[N];
    result_case_2 += dist[essential[0]];

    if(result_case_1 >= INF && result_case_2 >= INF) result = -1;
    else result = min(result_case_1, result_case_2);

    cout << result << endl;

    return 0;
}