#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    lli start = 1, end, k;
    cin >> N >> k;
    end = k;
    
    while(start <= end)
    {
        lli mid = (start + end) / 2;
        lli cnt = 0;
        for(lli i = 1; i <= N; i++)
        {
            if(mid % i == 0) cnt += min(mid / i, (lli)N);
            else cnt += min(mid / i, (lli)N);
        }

        if(cnt < k) start = mid + 1;
        else end = mid - 1;
    }

    cout << start << '\n';
    
    return 0;
}