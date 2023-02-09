#include <iostream>

using namespace std;

int num_weight, num_bead;
int weight[31];
int dp[40001][31];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num_weight;

    for (int i = 0; i < num_weight; i++) cin >> weight[i];

    dp[20000][0] = 1;
    dp[20000-weight[0]][0] = 1;
    dp[20000+weight[0]][0] = 1;

    for (int i = 1; i < num_weight; i++) 
    {
        for (int j = 0; j <= 40000; j++) 
        {
            if (dp[j][i - 1] == 1) 
            {
                dp[j][i] = 1;
                dp[j + weight[i]][i] = 1;
                dp[j - weight[i]][i] = 1;
            }
        }
    }

    cin >> num_bead;

    for (int i = 0; i < num_bead; i++) 
    {
        int bead;
        cin >> bead;
        if (bead > 20000) cout << "N ";
        else if (dp[20000 + bead][num_weight - 1] == 1) cout << "Y ";
        else cout << "N ";
    }
    
    return 0;
}