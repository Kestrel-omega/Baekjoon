#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull N, M;
    ull count_2 = 0, count_5 = 0;
    
    cin >> N >> M;

    for (ull i = 2; i <= N; i *= 2)
    {
        count_2 += N / i;
        if(i <= N - M) count_2 -= (N - M) / i;
        if(i <= M) count_2 -= M / i;
    }

    for (ull i = 5; i <= N; i *= 5)
    {
        count_5 += N / i;
        if(i <= N - M) count_5 -= (N - M) / i;
        if(i <= M) count_5 -= M / i;
    }

    cout << min(count_2, count_5) << '\n';
    
    return 0;
}