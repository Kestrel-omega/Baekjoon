#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <list>

using namespace std;

// 9328 열쇠

char map[102][102];
bool visited[102][102];

int T, H, W;
int answer;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

string key;
list<pair<int, int>> door;

void BFS(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    visited[start_x][start_y] = true;
    q.push({start_x, start_y});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx == -1 || nx == H + 2 || ny == -1 || ny == W + 2) continue;
            if (map[nx][ny] == '*') continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            /* 문 */
            if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z')
            {
                /* 문에 해당하는 열쇠가 없다면 */
                if (key.find(map[nx][ny] - ('A' - 'a')) == string::npos)
                {
                    door.push_back({nx, ny});
                    continue;
                }
            }
            /* 열쇠 */
            if ('a' <= map[nx][ny] && map[nx][ny] <= 'z')
            {
                /* 해당 열쇠를 이미 가지고 있다면 */
                if (key.find(map[nx][ny] - ('A' - 'a')) != string::npos)
                    continue;
                key += map[nx][ny];
            }
            /* 문서 */
            if (map[nx][ny] == '$')
                answer++;

            q.push({nx, ny});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        queue<pair<int, int>> check_x_y;
        char str[101];
        
        cin >> H >> W;

        for (int i = 1; i <= H; i++)
        {
            cin >> str;
            for (int j = 1; j <= W; j++) map[i][j] = str[j - 1];
        }
        cin >> str;
        key = str;

        if (key == "0") key = "";

        for (int i = 0; i <= H + 1; i++)
        {
            for (int j = 0; j <= W + 1; j++)
            {
                if (i == 0 || i == H + 1 || j == 0 || j == W + 1) map[i][j] = '.';
                visited[i][j] = false;
            }
        }

        check_x_y.push({0, 0});

        while (!check_x_y.empty())
        {
            int x = check_x_y.front().first;
            int y = check_x_y.front().second;
            check_x_y.pop();

            BFS(x, y);

            list<pair<int, int>>::iterator iter;
            int len = key.length();

            for (int i = 0; i < len; i++)
            {
                for (iter = door.begin(); iter != door.end(); iter++)
                    if (key[i] == map[iter->first][iter->second] - ('A' - 'a'))
                    {
                        check_x_y.push({iter->first, iter->second});
                        iter = door.erase(iter);
                        iter--;
                    }
            }
        }
        
        cout << answer << endl;

        for(int i = 0; i < 101; i++)
        {
            for(int j = 0; j < 101; j++)
            {
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
            
        answer = 0;
        door.clear();
        key.clear();
    }

    return 0;
}