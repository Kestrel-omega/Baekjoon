#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct ball
{
    int rx, ry, bx, by, count;
};

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
ball cur;
string map[10];
queue<ball> ball_path;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 'R')
            {
                cur.rx = i;
                cur.ry = j;
            }
            else if (map[i][j] == 'B')
            {
                cur.bx = i;
                cur.by = j;
            }
        }
    }

    ball_path.push(cur);

    while (!ball_path.empty())
    {
        cur = ball_path.front();
        ball_path.pop();
        if (cur.count > 10)
        {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int rx = cur.rx;
            int ry = cur.ry;
            int bx = cur.bx;
            int by = cur.by;
            int rc = 0;
            int bc = 0;
            while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O')
            {
                rx += dx[i];
                ry += dy[i];
                rc++;
            }
            while (map[bx + dx[i]][by + dy[i]] != '#' && map[bx][by] != 'O')
            {
                bx += dx[i];
                by += dy[i];
                bc++;
            }
            if (map[bx][by] == 'O') continue;
            if (map[rx][ry] == 'O')
            {
                if(cur.count < 10) cout << cur.count + 1;
                else cout << -1;
                return 0;
            }
            if (rx == bx && ry == by)
            {
                if (rc > bc)
                {
                    rx -= dx[i];
                    ry -= dy[i];
                }
                else
                {
                    bx -= dx[i];
                    by -= dy[i];
                }
            }

            ball next;
            next.rx = rx;
            next.ry = ry;
            next.bx = bx;
            next.by = by;
            next.count = cur.count + 1;
            ball_path.push(next);
        }
    }

    cout << -1;

    return 0;
}