#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, point_first = 0, point_second = 0, min_val = 100001;
    long long int sum = 0, S;
    vector<int> v;

    cin >> N >> S;
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    while(point_first <= point_second)
    {
        if(sum >= S)
        {
            min_val = min(min_val, point_second - point_first);
            sum -= v[point_first];
            point_first++;
        }
        else if(point_second == N) break;
        else 
        {
            sum += v[point_second];
            point_second++;
        }
    }

    if (min_val == 100001) cout << 0;
    else cout << min_val;
    
    return 0;
}