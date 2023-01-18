#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, result;
    
    cin >> T;
    while(T--)
    {
        map <string, int> clothes;
        result = 1;
        cin >> N;
        while(N--)
        {
            
            string name, kind;
            cin >> name >> kind;

            if(clothes.find(kind) == clothes.end())
            {
                clothes.insert(make_pair(kind, 1));
            }
            else clothes[kind] += 1;
        }

        for(auto it = clothes.begin(); it != clothes.end(); it++)
        {
            result *= (it->second + 1);
        }

        cout << result - 1 << "\n";
    }
        
    return 0;
}