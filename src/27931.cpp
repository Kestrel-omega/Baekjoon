#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int even = 1e9 + 1;
    int odd = 1e9 + 1;

    for (int i = 0; i < n - 1; i++)
    {
        int diff = v[i + 1] - v[i];
        if (diff % 2 == 0) even = min(even, diff);
        else odd = min(odd, diff);
    }

    if (even == 1e9 + 1 && n > 2)
    {
        for (int i = 0; i < n - 2; i++)
        {
            int diff = v[i + 2] - v[i];
            even = min(even, diff);
        }
    }

    if (even == 1e9 + 1) even = -1;
    if (odd == 1e9 + 1) odd = -1;

    cout << even << ' ' << odd;

    return 0;
}