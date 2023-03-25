// 1167. 트리의 지름

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, max_dist = 0, max_node = 0;
vector<pair<int, int>> tree[100001];
int dist[100001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i].first;
            int nextdist = tree[cur][i].second;

            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + nextdist;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a;

        while(1)
        {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            tree[a].push_back({b, c});
        }
    }

    fill(dist, dist + 100001, -1);
    bfs(1);

    for (int i = 1; i <= N; i++)
    {
        if (max_dist < dist[i])
        {
            max_dist = dist[i];
            max_node = i;
        }
    }

    fill(dist, dist + 100001, -1);
    bfs(max_node);

    max_dist = 0;
    for (int i = 1; i <= N; i++)
    {
        if (max_dist < dist[i]) max_dist = dist[i];
    }

    cout << max_dist;

    return 0;
}