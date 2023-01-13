#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, data, iter = 0;
    cin >> N;
    queue<int> q;
    
    while(true)
    {
        cin >> data;
        if(data == -1) break;
        else if(data == 0) 
        {
            q.pop();
            iter--;
        }
        else if(iter < N)
        {
            q.push(data);
            iter++;
        }
        else continue;
    }

    if(q.empty()) cout << "empty";
    else
    {
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
    
    return 0;
}