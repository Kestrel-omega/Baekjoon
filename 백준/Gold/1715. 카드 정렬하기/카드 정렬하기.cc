#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }

    cout << sum << endl;
    
    return 0;
}