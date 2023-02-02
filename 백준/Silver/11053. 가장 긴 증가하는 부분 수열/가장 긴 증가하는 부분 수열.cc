#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, max_length = 0;
    vector<int> A;
    vector<int> dp;

    cin >> N;

    while(N--)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
        dp.push_back(1);
    }

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }

    cout << max_length << "\n";
    
    return 0;
}