#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C, X[200001], left = 1, right, count = 1, mid, answer = 0, idx, dist;

    cin >> N >> C;

    for (int i = 0; i < N; i++) cin >> X[i];

    sort(X, X + N);

    right = X[N - 1] - X[0];

    while (left <= right)
    {
        mid = (left + right) / 2;
        idx = 0;
        count = 1;

        for (int i = 1; i < N; i++)
        {
            dist = X[i] - X[idx];

            if (dist >= mid)
            {
                count++;
                idx = i;
            }
        }

        if (count >= C)
        {
            answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << answer;

    return 0;
}