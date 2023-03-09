#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, length, idx, temp;
    int arr[1002] = {0,};
    int dp[1002] = {0,};
    vector<int> sequence;

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        length = 0;
        cin >> arr[i];
        
        for(int j = 1; j < i; j++)
        {
            if(arr[j] < arr[i]) length = max(length, dp[j]);
        }
        dp[i] = length + 1;

        if(temp < dp[i])
        {
            temp = length + 1;
            idx = i;
        }
    }

    for(int i = idx; i > 0; i--)
    {
        if(dp[i] == temp)
        {
            sequence.push_back(arr[i]);
            temp--;
        }
    }

    if(sequence.size() != 0)
    {
        cout << sequence.size() << "\n";
        for(int i = sequence.size() - 1; i >= 0; i--) cout << sequence[i] << " ";
    }
    else cout << 1 << "\n" << arr[1];
    
    return 0;
}