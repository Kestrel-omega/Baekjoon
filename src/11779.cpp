#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int count = 0;
int dist[1001];
int path[1001] = {0, };
int N, M, start, finish;
vector<pair<int, int>> cur_cost[1001];
vector<int> answer;

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (int i = 0; i < cur_cost[cur].size(); i++)
        {
            int next = cur_cost[cur][i].first;
            int next_cost = cost + cur_cost[cur][i].second;
            if (dist[next] > next_cost)
            {
                dist[next] = next_cost;
                pq.push(make_pair(-next_cost, next));
                path[next] = cur;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cur_cost[a].push_back(make_pair(b, c));
    }

    cin >> start >> finish;

    for (int i = 1; i <= N; i++) dist[i] = 2147483647;

    dijkstra(start);

    int cur = finish;

    while (cur != start)
    {
        answer.push_back(cur);
        cur = path[cur];
    }
    answer.push_back(start);

    cout << dist[finish] << "\n";
    cout << answer.size() << "\n";

    for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i] << " ";
    
    return 0;
}