#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    int answer = 0;
    int dist[401][401] = {0,};

    cin >> V >> E;

    while(E--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        if(dist[from][to] == 0) dist[from][to] = cost;
        else dist[from][to] = min(dist[from][to], cost);
    }

    for(int k = 1; k <= V; k++)
    {
        for(int i = 1; i <= V; i++)
        {
            for(int j = 1; j <= V; j++)
            {
                if(dist[i][k] != 0 && dist[k][j] != 0)
                {
                    if(dist[i][j] == 0) dist[i][j] = dist[i][k] + dist[k][j];
                    else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        if(dist[i][i] != 0)
        {
            if(answer == 0) answer = dist[i][i];
            else answer = min(answer, dist[i][i]);
        }
    }

    if(answer == 0) cout << -1 << "\n";
    else cout << answer << "\n";

    return 0;
}