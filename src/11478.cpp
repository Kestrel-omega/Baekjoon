#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    set<string> set_S;
    cin >> S;

    for(int i = 0; i < S.length(); i++)
    {
        string str;
        for(int j = i; j < S.length(); j++)
        {
            str += S[j];
            set_S.insert(str);
        }
    }
    
    cout << set_S.size();
    
    return 0;
}