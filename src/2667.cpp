#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, cnt = 0;
    int board[25][25];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool visited[25][25] = {false, };
    queue<pair<int, int>> map_x_y;
    vector<int> num_building;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++) board[i][j] = temp[j] - '0';
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1 && !visited[i][j])
            {
                cnt++;
                map_x_y.push({i, j});
                visited[i][j] = true;
                int num = 0;
                while (!map_x_y.empty())
                {
                    int x = map_x_y.front().first;
                    int y = map_x_y.front().second;
                    num++;
                    map_x_y.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (visited[nx][ny] == true) continue;
                        if (board[nx][ny] == 1)
                        {
                            map_x_y.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }
                    }
                }
                num_building.push_back(num);
            }
        }
    }

    std::sort(num_building.begin(), num_building.end());

    std::cout << cnt << "\n";

    for(int num_complex : num_building) std::cout << num_complex << "\n";
    
    return 0;
}