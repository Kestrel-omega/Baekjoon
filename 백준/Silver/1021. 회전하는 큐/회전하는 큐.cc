#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int N, M, index, num, count = 0;
    deque<int> dq;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    for (int i = 0; i < M; i++)
    {
        cin >> num;

        for (int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == num)
            {
                index = i;
                break;
            }
        }

        while (1)
        {
            if (num == dq.front())
            {
                dq.pop_front();
                break;
            }

            if (index > (dq.size() / 2))
            {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
            else
            {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}