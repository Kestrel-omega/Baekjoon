#include <iostream>
#include <algorithm>

using namespace std;

bool check[9];
int N, M, arr[9], result[9];

void make_sequence(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int before = 0;

    for (int i = 0; i < N; i++)
    {
        if (!check[i] && before != arr[i])
        {
            check[i] = true;
            result[cnt] = arr[i];
            before = arr[i];
            make_sequence(cnt + 1);
            check[i] = false;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    make_sequence(0);
    
    return 0;
}