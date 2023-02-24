#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int basket[101] = {0,};

    cin >> N >> M;

    for (int i = 1; i <= N; i++) basket[i] = i;

    while (M--)
    {
        int i, j;

        cin >> i >> j;

        for (i; i <= j; i++)
        {
            swap(basket[i], basket[j]);
            j--;
        }
    }
    for (int i = 1; i <= N; i++) cout << basket[i] << " ";

    return 0;
}