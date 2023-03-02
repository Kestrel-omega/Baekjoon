#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int dist_cost[101][101] = {0,};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while(m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        if(dist_cost[from][to] == 0) dist_cost[from][to] = cost;
        else dist_cost[from][to] = min(dist_cost[from][to], cost);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist_cost[i][k] != 0 && dist_cost[k][j] != 0)
                {
                    if(dist_cost[i][j] == 0) dist_cost[i][j] = dist_cost[i][k] + dist_cost[k][j];
                    else dist_cost[i][j] = min(dist_cost[i][j], dist_cost[i][k] + dist_cost[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << dist_cost[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}