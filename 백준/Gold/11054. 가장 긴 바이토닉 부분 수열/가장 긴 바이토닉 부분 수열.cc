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
    vector<int> array;
    vector<int> max_dp, min_dp;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
        max_dp.push_back(1);
        min_dp.push_back(1);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] > array[j]) max_dp[i] = max(max_dp[i], max_dp[j] + 1);
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (array[i] > array[j]) min_dp[i] = max(min_dp[i], min_dp[j] + 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        max_length = max(max_length, max_dp[i] + min_dp[i] - 1);
    }
    
    cout << max_length << "\n";

    
    return 0;
}