#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    deque<pair<int, int>> time;
    int iter, max, current_time, cursor = 0;
    cin >> iter;
    while(iter--)
    {
        int start, end;
        cin >> start >> end;

        time.push_back(make_pair(end,start));
    }

    sort(time.begin(), time.end());

    current_time = time[0].first;
    
    max = 1;

    for(int i = 1; i < time.size(); i++)
    {
        if(time[i].second >= current_time)
        {
            current_time = time[i].first;
            max++;
        }
    }

    cout << max;

    return 0;
}