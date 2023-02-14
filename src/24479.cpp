#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited, sequence;
int cnt = 0;

void dfs(int node)
{
    cnt++;
    sequence[node] = cnt;
    visited[node] = 1;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if (visited[next] == 0) dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R;
    
    cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1);
    sequence.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    dfs(R);

    for (int i = 1; i <= N; i++) cout << sequence[i] << "\n";
    
    return 0;
}