#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    int answer[50001] = {0, 1, };

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        answer[i] = answer[1] + answer[i-1];
        for(int j = 2; j * j <= i; j++) answer[i] = min(answer[i], answer[i-j*j]+1);
    }

    cout << answer[n];
    
    return 0;
}