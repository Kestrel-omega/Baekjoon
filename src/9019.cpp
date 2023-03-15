#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int A, B;
bool visited[10000];

void bfs()
{
    queue<pair<int, string>> num_command;
    num_command.push(make_pair(A, ""));
    visited[A] = true;

    while(!num_command.empty())
    {
        int num = num_command.front().first;
        string command = num_command.front().second;
        num_command.pop();

        if(num == B)
        {
            cout << command << '\n';
            return;
        }

        int D = (num * 2) % 10000;
        if(!visited[D])
        {
            visited[D] = true;
            num_command.push(make_pair(D, command + "D"));
        }

        int S = num - 1;
        if(S == -1) S = 9999;
        if(!visited[S])
        {
            visited[S] = true;
            num_command.push(make_pair(S, command + "S"));
        }

        int L = (num % 1000) * 10 + num / 1000;
        if(!visited[L])
        {
            visited[L] = true;
            num_command.push(make_pair(L, command + "L"));
        }

        int R = (num % 10) * 1000 + num / 10;
        if(!visited[R])
        {
            visited[R] = true;
            num_command.push(make_pair(R, command + "R"));
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        for(int i = 0; i < 10000; i++) visited[i] = false;
        cin >> A >> B;
        bfs();
    }
    
    return 0;
}