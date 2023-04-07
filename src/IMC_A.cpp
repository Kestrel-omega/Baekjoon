#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, U, D;
    int U_cnt = 0, D_cnt = 0, U_D_cnt = 0;
    cin >> N;
    
    vector<int> clothes(N);
    vector<char> ans(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> clothes[i];
        if (clothes[i] == 1) 
        {
            ans[i] = 'U';
            U_cnt++;
        }
        else if (clothes[i] == 2)
        {
            ans[i] = 'D';
            D_cnt++;
        }
        else if (clothes[i] == 3)
        {
            U_D_cnt++;
        }
    }
    cin >> U >> D;

    if (U_cnt + U_D_cnt < U || D_cnt + U_D_cnt < D)
    {
        cout << "NO";
        return 0;
    }
    else cout << "YES\n";

    U = U - U_cnt;
    D = D - D_cnt;

    for (int i = 0; i < N; i++)
    {
        if (clothes[i] == 3)
        {
            if (U > 0)
            {
                ans[i] = 'U';
                U--;
            }
            else
            {
                ans[i] = 'D';
                D--;
            }
        }
    }

    for (char c : ans) cout << c;

    return 0;
}