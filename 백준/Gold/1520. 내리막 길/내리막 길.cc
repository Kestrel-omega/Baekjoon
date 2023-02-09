#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[501][501];
int dp[501][501];
bool is_visited[501][501] = {false};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y)
{
    if(x == N && y == M) return 1;

    if(is_visited[x][y]) return dp[x][y];

    is_visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 1 && nx <= N && ny >= 1 && ny <= M)
        {
            if(map[x][y] > map[nx][ny]) dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++) cin >> map[i][j];
    }

    cout << dfs(1, 1) << endl;

    return 0;
}