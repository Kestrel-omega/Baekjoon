#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int ans = 0;

    cin >> N;

    vector<pair<int, int>> ramen_deadline(N);
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) cin >> ramen_deadline[i].first >> ramen_deadline[i].second;

    sort(ramen_deadline.begin(), ramen_deadline.end());

    
    for (int i = 0; i < N; i++)
    {
        pq.push(-ramen_deadline[i].second);
        if (pq.size() > ramen_deadline[i].first) pq.pop();
    }

    while (!pq.empty())
    {
        ans += -pq.top();
        pq.pop();
    }
    
    cout << ans;
        
    return 0;
}