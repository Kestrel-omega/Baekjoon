#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001] = {0,};
vector<int> sequence;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while(N--)
    {
        int a;
        cin >> a;
        sequence.push_back(a);
    }

    

    
    return 0;
}