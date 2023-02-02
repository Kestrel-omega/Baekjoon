#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> array, dp;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
        dp.push_back(temp);
    }

    int max_sum = array[0];

    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + array[i]);
        if(dp[i] > max_sum) max_sum = dp[i];
    }
    cout << max_sum;

    return 0;
}