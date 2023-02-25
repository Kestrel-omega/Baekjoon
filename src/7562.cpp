#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int start_x, start_y, end_x, end_y;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int chess_plate[301][301] = {0, };
bool visited[301][301] = {false, };
queue<pair<int, int>> q;

void reset()
{
    while(!q.empty()) q.pop();
    for(int i = 0; i < 301; i++)
    {
        for(int j = 0; j < 301; j++)
        {
            chess_plate[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void bfs(int x, int y, int plate_size)
{
    q.push(make_pair(x, y));
    visited[x][y] = true;
    chess_plate[x][y] = true;

    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        if(cur_x == end_x && cur_y == end_y)
        {
            cout << chess_plate[cur_x][cur_y] - 1 << "\n";
            return;
        }

        for(int i = 0; i < 8; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= 0 && next_x < plate_size && next_y >= 0 && next_y < plate_size)
            {
                if(!visited[next_x][next_y])
                {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = true;
                    chess_plate[next_x][next_y] = chess_plate[cur_x][cur_y] + 1;
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    reset();

    while(test_case--)
    {
        int I;
        cin >> I;
        cin >> start_x >> start_y >> end_x >> end_y;

        bfs(start_x, start_y, I);
        reset();
    }
    
    return 0;
}