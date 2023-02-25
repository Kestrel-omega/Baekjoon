#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int date = 0;
int M, N;
int tomato[1001][1001] = {0, };
bool visited[1001][1001] = {false, };
queue<pair<int, int>> q;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 1. left
            if(x - 1 >= 0 && tomato[x - 1][y] == 0 && !visited[x - 1][y])
            {
                q.push(make_pair(x - 1, y));
                visited[x - 1][y] = true;
                tomato[x - 1][y] = 1;
            }
            // 2. right
            if(x + 1 < N && tomato[x + 1][y] == 0 && !visited[x + 1][y])
            {
                q.push(make_pair(x + 1, y));
                visited[x + 1][y] = true;
                tomato[x + 1][y] = 1;
            }
            // 3. up
            if(y - 1 >= 0 && tomato[x][y - 1] == 0 && !visited[x][y - 1])
            {
                q.push(make_pair(x, y - 1));
                visited[x][y - 1] = true;
                tomato[x][y - 1] = 1;
            }
            // 4. down
            if(y + 1 < M && tomato[x][y + 1] == 0 && !visited[x][y + 1])
            {
                q.push(make_pair(x, y + 1));
                visited[x][y + 1] = true;
                tomato[x][y + 1] = 1;
            }
        }
        date++;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(tomato[i][j] == 0)
            {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << date - 1 << "\n";
    
    return 0;
}