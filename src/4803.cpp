#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, u, v, answer;
bool is_visited[501];
vector<int> graph[501];

bool dfs(int node, int post_node)
{
    is_visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next_node = graph[node][i];
        if (next_node == post_node) continue;
        if (is_visited[next_node]) return false;
        if (!dfs(next_node, node)) return false;
    }

    return true;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 0;

    while(1)
    {
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        test_case++;
        answer = 0;

        for (int i = 1; i <= 500; i++)
        {
            graph[i].clear();
            is_visited[i] = false;
        }

        for (int i = 0; i < M; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!is_visited[i])
            {
                if(dfs(i, 0)) answer++;
            }
        }

        cout << "Case " << test_case << ": ";
        if(answer > 1) cout << "A forest of " << answer << " trees.\n";
        else if(answer == 1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
    }

    return 0;
}