#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool map[101][101] = {0, };
    bool checked[101] = {0, };
    queue<int> bfs_queue;
    
    int infected_computer = 0;
    int num_computer, num_pair;
    cin >> num_computer >> num_pair;

    while(num_pair--)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }
   
    checked[1] = true;
    bfs_queue.push(1);
    while(!bfs_queue.empty())
    {
        int from = bfs_queue.front();
        bfs_queue.pop();
        for(int i = 1; i <= num_computer; i++)
        {
            if(checked[i] == false && map[from][i] == true)
            {
                bfs_queue.push(i);
                checked[i] = true;
                infected_computer++;
            }
        }
    }

    cout << infected_computer << endl;
    
    return 0;
}