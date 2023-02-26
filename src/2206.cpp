#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct _node
{
    int x;
    int y;
    int cnt;
    int crash;
} Node;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<Node> node;
    int N, M;
    int map[1001][1001];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visited[1001][1001][2];

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++) map[i][j] = str[j - 1] - '0';
    }

    node.push({1, 1, 1, 0});

    while (!node.empty())
    {
        Node cur = node.front();
        node.pop();

        if (cur.x == N && cur.y == M)
        {
            cout << cur.cnt;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

            if (map[nx][ny] == 0 && !visited[nx][ny][cur.crash])
            {
                visited[nx][ny][cur.crash] = true;
                node.push({nx, ny, cur.cnt + 1, cur.crash});
            }
            else if (map[nx][ny] == 1 && cur.crash == 0)
            {
                visited[nx][ny][1] = true;
                node.push({nx, ny, cur.cnt + 1, 1});
            }
        }
    }

    cout << -1;
    
    return 0;
}