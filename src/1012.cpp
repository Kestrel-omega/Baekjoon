#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M, N, K, x, y;

    cin >> T;

    while(T--)
    {
        cin >> M >> N >> K;
        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<bool>> is_visited(N, vector<bool>(M, false));
        int cnt = 0;

        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;
            board[y][x] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 1 && !is_visited[i][j])
                {
                    cnt++;
                    queue<pair<int, int>> map_x_y;
                    map_x_y.push({i, j});
                    is_visited[i][j] = true;
                    while (!map_x_y.empty())
                    {
                        int x = map_x_y.front().first;
                        int y = map_x_y.front().second;
                        map_x_y.pop();
                        if (x - 1 >= 0 && board[x - 1][y] == 1 && !is_visited[x - 1][y])
                        {
                            map_x_y.push({x - 1, y});
                            is_visited[x - 1][y] = true;
                        }
                        if (x + 1 < N && board[x + 1][y] == 1 && !is_visited[x + 1][y])
                        {
                            map_x_y.push({x + 1, y});
                            is_visited[x + 1][y] = true;
                        }
                        if (y - 1 >= 0 && board[x][y - 1] == 1 && !is_visited[x][y - 1])
                        {
                            map_x_y.push({x, y - 1});
                            is_visited[x][y - 1] = true;
                        }
                        if (y + 1 < M && board[x][y + 1] == 1 && !is_visited[x][y + 1])
                        {
                            map_x_y.push({x, y + 1});
                            is_visited[x][y + 1] = true;
                        }
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}