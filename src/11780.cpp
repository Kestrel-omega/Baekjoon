#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];
int path[101][101];
int N, M, i, j, k;
vector<int> answer;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++) if (i != j) map[i][j] = 1e9;
    }

    while(M--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (map[a][b] > c)
        {
            map[a][b] = c;
            path[a][b] = a;
        }
    }

    for (k = 1; k <= N; k++)
    {
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (map[i][j] == 1e9) cout << 0 << " ";
            else cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
        {
            if (map[i][j] == 1e9 || map[i][j] == 0) cout << 0 << "\n";
            else
            {
                int cur = j;
                answer.push_back(cur);
                while (path[i][cur] != i)
                {
                    cur = path[i][cur];
                    answer.push_back(cur);
                }
                answer.push_back(i);
                cout << answer.size() << " ";
                for (int k = answer.size() - 1; k >= 0; k--) cout << answer[k] << " ";
                cout << "\n";
                answer.clear();
            }
        }
    }
    
    return 0;
}