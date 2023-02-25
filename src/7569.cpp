#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int date = 0;
int M, N, H;
int tomato[101][101][101] = {0, };
bool visited[101][101][101] = {false, };
queue<tuple<int, int, int>> position;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1)
                {
                    position.push(make_tuple(i, j, k));
                    visited[i][j][k] = true;
                }
            }
        }
    }

    while(!position.empty())
    {
        int size = position.size();
        for(int i = 0; i < size; i++)
        {
            int x = get<0>(position.front());
            int y = get<1>(position.front());
            int z = get<2>(position.front());
            position.pop();

            // 1. left
            if(z - 1 >= 0 && tomato[x][y][z - 1] == 0 && !visited[x][y][z - 1])
            {
                position.push(make_tuple(x, y, z - 1));
                visited[x][y][z - 1] = true;
                tomato[x][y][z - 1] = 1;
            }
            // 2. right
            if(z + 1 < M && tomato[x][y][z + 1] == 0 && !visited[x][y][z + 1])
            {
                position.push(make_tuple(x, y, z + 1));
                visited[x][y][z + 1] = true;
                tomato[x][y][z + 1] = 1;
            }
            // 3. up
            if(y - 1 >= 0 && tomato[x][y - 1][z] == 0 && !visited[x][y - 1][z])
            {
                position.push(make_tuple(x, y - 1, z));
                visited[x][y - 1][z] = true;
                tomato[x][y - 1][z] = 1;
            }
            // 4. down
            if(y + 1 < N && tomato[x][y + 1][z] == 0 && !visited[x][y + 1][z])
            {
                position.push(make_tuple(x, y + 1, z));
                visited[x][y + 1][z] = true;
                tomato[x][y + 1][z] = 1;
            }
            // 5. front
            if(x - 1 >= 0 && tomato[x - 1][y][z] == 0 && !visited[x - 1][y][z])
            {
                position.push(make_tuple(x - 1, y, z));
                visited[x - 1][y][z] = true;
                tomato[x - 1][y][z] = 1;
            }
            // 6. back
            if(x + 1 < H && tomato[x + 1][y][z] == 0 && !visited[x + 1][y][z])
            {
                position.push(make_tuple(x + 1, y, z));
                visited[x + 1][y][z] = true;
                tomato[x + 1][y][z] = 1;
            }
        }
        date++;
    }

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                if(tomato[i][j][k] == 0)
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << date - 1;
    
    return 0;
}