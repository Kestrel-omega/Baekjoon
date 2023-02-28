#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define RED 1
#define BLUE 2

using namespace std;

int K, V, E;
vector<int> graph[20001];
short visited[20001] = {0,};

bool is_bipartite_graph()
{
    for(int i = 1; i <= V; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];
            if(visited[i] == visited[next]) return false;
        }
    }
    return true;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    while(K--)
    {
        cin >> V >> E;
        for(int i = 0; i < E; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        queue<int> node;

        for(int i = 1; i <= V; i++)
        {
            if(visited[i]) continue;
            node.push(i);
            visited[i] = RED;
            while(!node.empty())
            {
                int current = node.front();
                node.pop();
                for(int j = 0; j < graph[current].size(); j++)
                {
                    int next = graph[current][j];
                    if(visited[next] == 0)
                    {
                        visited[next] = (visited[current] == RED) ? BLUE : RED;
                        node.push(next);
                    }
                }
            }
        }

        if(is_bipartite_graph()) cout << "YES\n";
        else cout << "NO\n";

        for(int i = 1; i <= V; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }
    }
    
    return 0;
}