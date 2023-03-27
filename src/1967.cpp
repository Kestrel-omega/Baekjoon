#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, max_dist = 0, max_node = 0;
bool is_visited[10001] = {false, };
vector<pair<int, int>> tree[10001];

void dfs(int point, int length)
{
    is_visited[point] = true;

    for (int i = 0; i < tree[point].size(); i++)
    {
        int next = tree[point][i].first;
        int next_length = tree[point][i].second;

        if (is_visited[next] == false)
        {
            dfs(next, length + next_length);
        }
    }

    if (max_dist < length)
    {
        max_dist = length;
        max_node = point;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    dfs(1, 0);

    fill(is_visited, is_visited + 10001, false);
    dfs(max_node, 0);

    cout << max_dist;
    
    return 0;
}