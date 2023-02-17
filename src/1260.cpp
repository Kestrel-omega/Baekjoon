#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, R;
queue<int> que;
bool graph[1001][1001] = { false, };
bool is_visited[1001] = { false, };

void dfs(int node)
{
	is_visited[node] = true;
    cout << node << " ";

	for (int i = 1; i <= N; i++) if(graph[node][i] && !is_visited[i]) dfs(i);		
}

void bfs(int node)
{
    is_visited[node] = true;
    que.push(node);
    cout << node << " ";

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for (int i = 1; i <= N; i++)
        {
            if (graph[cur][i] && !is_visited[i])
            {
                is_visited[i] = true;
                que.push(i);
                cout << i << " ";
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;

	// input graph
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
	}

    dfs(R);
    cout << "\n";

    fill_n(is_visited, 1001, false);
    bfs(R);
    
	return 0;
}