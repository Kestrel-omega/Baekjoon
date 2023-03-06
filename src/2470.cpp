#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int point_first = 0, point_second = N-1, point_min_front, point_min_back, min = 2147483647;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    while(point_first < point_second)
    {
        if (abs(v[point_first] + v[point_second]) < min)
        {
            min = abs(v[point_first] + v[point_second]);
            point_min_front = point_first;
            point_min_back = point_second;
        }
        if (v[point_first] + v[point_second] > 0) point_second--;
        else point_first++;
    }

    cout << v[point_min_front] << " " << v[point_min_back] << "\n";
    
    return 0;
}