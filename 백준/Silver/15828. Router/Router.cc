#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, data;
    cin >> N;
    queue<int> q;

    cin >> data;
    while(data != -1)
    {
        if(q.size() < N)
        {
            if(data == 0) q.pop();
            else q.push(data);
        }
        cin >> data;
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