#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, l, r;
    char c;
    string S;
    vector<int> prefix_sum[26];

    cin >> S;
    
    for (int i = 0; i < S.size(); ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            int idx = S[i] - 'a';
            if (i == 0)
            {
                if (idx == j) prefix_sum[j].push_back(1);
                else prefix_sum[j].push_back(0);
            }
            else
            {
                if (idx == j) prefix_sum[j].push_back(prefix_sum[j][i - 1] + 1);
                else prefix_sum[j].push_back(prefix_sum[j][i - 1]);
            }
        }
    }

    cin >> q;

    while(q--)
    {
        cin >> c >> l >> r;
        int idx = c - 'a';

        if (l == 0) cout << prefix_sum[idx][r] << "\n";
        else cout << prefix_sum[idx][r] - prefix_sum[idx][l - 1] << "\n";
    }
}