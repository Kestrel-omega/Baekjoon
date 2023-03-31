#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    vector<int> tree[n + 1];
    int parent[n + 1] = {0, };
    bool is_visited[n + 1] = {false, };

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    q.push(1);
    is_visited[1] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i];
            if (!is_visited[next])
            {
                is_visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }

    for (int i = 2; i <= n; i++) cout << parent[i] << '\n';

    return 0;
}