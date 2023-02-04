#include <iostream>

using namespace std;

typedef long long int lli;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N, answer = 0;
    int lan_length[10001];
    lli low = 1, mid, high = 0;

    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        cin >> lan_length[i];
        if (high < lan_length[i]) high = lan_length[i];   
    }

    while(low <= high)
    {
        mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < K; i++) count += lan_length[i] / mid;
        if (count >= N)
        {
            if (answer < mid) answer = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << answer << "\n";

    
    return 0;
}