#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, cnt = 0;
    cin >> N >> K;

    vector<int> sequence(K);
    vector<int> plug(N, -1);

    for (int i = 0; i < K; i++) cin >> sequence[i];

    for (int i = 0; i < K; i++)
    {
        bool flag = false;
        int idx = 0, max_idx = 0;

        for (int j = 0; j < N; j++)
        {
            if (plug[j] == sequence[i])
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        for (int j = 0; j < N; j++)
        {
            if (plug[j] == -1)
            {
                plug[j] = sequence[i];
                flag = true;
                break;
            }
        }
        if (flag) continue;
        
        for (int j = 0; j < N; j++)
        {
            int temp = 0;
            for (int k = i + 1; k < K; k++)
            {
                if (plug[j] == sequence[k]) break;
                temp++;
            }
            if (temp > max_idx)
            {
                max_idx = temp;
                idx = j;
            }
        }
        plug[idx] = sequence[i];
        cnt++;
    }

    cout << cnt;

    return 0;
}