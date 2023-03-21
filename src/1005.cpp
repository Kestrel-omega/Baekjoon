#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, K, W;
    
    cin >> T;

    while (T--)
    {
        cin >> N >> K;
        vector<int> delay(N + 1);
        vector<int> indegree(N + 1);
        vector<int> result(N + 1);
        vector<vector<int>> graph(N + 1);
        queue<int> q;

        for (int i = 1; i <= N; i++) cin >> delay[i];

        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        cin >> W;

        for (int i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                result[i] = delay[i];
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < graph[cur].size(); i++)
            {
                int next = graph[cur][i];
                indegree[next]--;
                result[next] = max(result[next], result[cur] + delay[next]);
                if (indegree[next] == 0) q.push(next);
            }
        }

        cout << result[W] << "\n";
    }

    return 0;
}