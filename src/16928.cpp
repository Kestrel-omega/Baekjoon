#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int warp[101] = {0, };
int visited[101] = {0, };
queue<int> position;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N+M; i++)
    {
        int start, end;
        cin >> start >> end;
        warp[start] = end;
    }

    position.push(1);

    while(!position.empty())
    {
        int size = position.size();
        for(int i = 0; i < size; i++)
        {
            int x = position.front();
            position.pop();

            for(int j = 1; j <= 6; j++)
            {
                if(x + j > 100)
                {
                    cout << visited[100];
                    return 0;
                }
                if(warp[x + j] != 0 && !visited[warp[x + j]])
                {
                    position.push(warp[x + j]);
                    visited[warp[x + j]] = visited[x] + 1;
                }
                else if(warp[x + j] == 0 && !visited[x + j])
                {
                    position.push(x + j);
                    visited[x + j] = visited[x] + 1;
                }
            }
        }
    }
    
    return 0;
}