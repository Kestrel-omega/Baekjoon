#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count_print = 0;
    int T, N, M, priority;

    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        priority = 0;
        count_print = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            q.push(make_pair(i, temp));
            pq.push(temp);
        }

        while(!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value)
            {
                pq.pop();
                count_print++;
                if(index == M)
                {
                    cout << count_print << '\n';
                    break;
                }
            }
            else q.push(make_pair(index, value));
        }
    }
    
    return 0;
}