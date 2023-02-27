#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define RED 1
#define BLUE 2

using namespace std;

int V, E;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, V, E, u, v;
    vector<int> graph[20001];
    int color[20001];

    cin >> K;

    while(K--)
    {
        for(int i = 0; i < 20001; i++)
        {
            graph[i].clear();
            color[i] = 0;
        }

        cin >> V >> E;
        
        for(int i = 0; i < E; i++)
        {
            cin >> u >> v;
            graph[u].push_back(u);
            graph[v].push_back(v);
        }

        for(int i = 1; i <= V; i++)
        {
            if(color[i] == 0)
            {
                queue<int> q;
                q.push(i);
                color[i] = RED;

                while(!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    for(int i = 0; i < graph[cur].size(); i++)
                    {
                        int next = graph[cur][i];

                        if(color[next] == 0)
                        {
                            if(color[cur] == RED) color[next] = BLUE;
                            else color[next] = RED;
                            q.push(next);
                        }
                        else
                        {
                            if(color[cur] == color[next])
                            {
                                cout << "NO\n";
                                continue;
                            }
                        }
                    }
                }
            }
        }

        for(int i = 1; i <= V; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                if(color[i] == color[graph[i][j]])
                {
                    cout << "NO\n";
                    continue;
                }
            }
        }

        cout << "YES\n";
    }
    
    return 0;
}