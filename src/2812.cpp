#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    string num;
    string ans = "";

    cin >> N >> K >> num;

    for (int i = 0; i < N; i++)
    {
        while (K > 0 && ans.size() > 0 && ans.back() < num[i])
        {
            ans.pop_back();
            K--;
        }
        ans.push_back(num[i]);
    }

    while (K > 0)
    {
        ans.pop_back();
        K--;
    }

    cout << ans;

    return 0;
}