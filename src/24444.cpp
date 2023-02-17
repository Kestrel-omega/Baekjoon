#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, R;
int result[100001] = {0, };
int cnt = 0;
bool is_visited[100001] = {false, };
vector<int> graph[100001];
queue<int> que;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    que.push(R);
    is_visited[R] = true;
    cnt++;
    result[R] = cnt;
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if(!is_visited[next])
            {
                cnt++;
                result[next] = cnt;
                que.push(next);
                is_visited[next] = true;
            }
        }
    }

    for(int i = 1; i <= N; i++) cout << result[i] << '\n';
    
    return 0;
}