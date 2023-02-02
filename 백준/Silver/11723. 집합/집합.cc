#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool S[20] = {false};
    int N;
    string order;

    cin >> N;
    for(int i=0; i < N; i++)
    {
        cin >> order;
        // add
        if(order == "add")
        {
            int num;
            cin >> num;
            S[num-1] = true;
        }
        // remove
        else if(order == "remove")
        {
            int num;
            cin >> num;
            S[num-1] = false;
        }
        // check
        else if(order == "check")
        {
            int num;
            cin >> num;
            if(S[num-1] == false) cout << "0\n";
            else cout << "1\n";
        }
        // toggle
        else if(order == "toggle")
        {
            int num;
            cin >> num;
            if(S[num-1] == false) S[num-1] = true;
            else S[num-1] = false;
        }
        // all
        else if(order == "all")
        {
            fill_n(S, sizeof(S), true);
        }
        // empty
        else if(order == "empty")
        {
            fill_n(S, sizeof(S), false);
        }
    }
        
    return 0;
}