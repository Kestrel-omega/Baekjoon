#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, count = 0;
    cin >> n;
    int point_first = 0, point_second = n-1;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    cin >> x;

    sort(v.begin(), v.end());

    while (point_first < point_second)
    {
        if (v[point_second] + v[point_first] == x)
        {
            count++;
            point_second--;
        }
        else if (v[point_second] + v[point_first] > x) point_second--;
        else point_first++;
    }

    cout << count;
        
    return 0;
}