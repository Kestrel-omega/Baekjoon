#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string inst;
    queue<int> q;
    cin >> n;
    while(n--)
    {
        cin >> inst;
        if(inst == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(inst == "pop")
        {
            if(!q.empty()) 
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << "-1" << "\n";
        }
        else if(inst == "front")
        {
            if(!q.empty()) cout << q.front() << "\n";
            else cout << "-1" << "\n";
        }
        else if(inst == "back")
        {
            if(!q.empty()) cout << q.back() << "\n";
            else cout << "-1" << "\n";
        }
        else if(inst == "size") cout << q.size() << "\n";
        else if(inst == "empty") cout << q.empty() << "\n";
    }


    return 0;
}