#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool is_visited[100001] = {false, };

void bfs(int location)
{
    queue<pair<int, int>> x_sec;
    x_sec.push({location, 0});

    while (!x_sec.empty())
    {
        int x = x_sec.front().first;
        int sec = x_sec.front().second;
        x_sec.pop();

        if (x == K)
        {
            cout << sec << "\n";
            return;
        }

        if (x - 1 < 100001 && x - 1 >= 0 && !is_visited[x - 1])
        {
            x_sec.push({x - 1, sec + 1});
            is_visited[x - 1] = true;
        }

        if (x + 1 < 100001 && x + 1 >= 0  && !is_visited[x + 1])
        {
            x_sec.push({x + 1, sec + 1});
            is_visited[x + 1] = true;
        }

        if (x * 2 < 100001 && x * 2 >= 0 && !is_visited[x * 2])
        {
            x_sec.push({x * 2, sec + 1});
            is_visited[x * 2] = true;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    is_visited[N] = true;

    bfs(N);
    
    return 0;
}