#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, idx = 0;
    int C[300001];
    long long int answer = 0;
    pair<int,int> M_V[300001];
    priority_queue<int, vector<int>> pq;

    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> M_V[i].first >> M_V[i].second;
    for(int i = 0; i < K; i++) cin >> C[i];

    sort(M_V, M_V + N);
    sort(C, C + K);

    for(int i = 0; i < K; i++)
    {
        while(idx < N && M_V[idx].first <= C[i])
        {
            pq.push(M_V[idx].second);
            idx++;
        }
        if(!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';

    return 0;
}