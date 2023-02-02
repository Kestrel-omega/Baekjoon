#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int recursive[41] = {1, 1, };
    int dp[41] = {0, };

    int n;
    cin >> n;

    for(int i = 2; i < n; i++)
    {
        recursive[i] = recursive[i - 1] + recursive[i - 2];
    }

    cout << recursive[n-1] << " " << n-2 << endl;
    
    return 0;
}