#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<bool>> maze; // false : wall, true : path
vector<vector<bool>> is_visited;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int min_path = 0;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    is_visited[x][y] = true;
    int path = 1;

    while (!q.empty())
    {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == N - 1 && y == M - 1)
            {
                min_path = path;
                return;
            }

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (is_visited[nx][ny] == true) continue;
                if (maze[nx][ny] == false) continue;

                q.push({nx, ny});
                is_visited[nx][ny] = true;
            }
        }
        path++;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    maze.resize(N, vector<bool>(M, false));
    is_visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) if (temp[j] == '1') maze[i][j] = true;
    }

    bfs(0, 0);

    cout << min_path << endl;
    
    return 0;
}