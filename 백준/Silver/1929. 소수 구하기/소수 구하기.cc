#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int arr[1000001] = { 0, };

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int M, N, i, j;
    cin >> N >> M;

    int sM = sqrt(M);

    for (i = 2; i <= M; i++)
        arr[i] = i;
    arr[0] = 0;
    arr[1] = 0;

    for (i = 2; i <= sM; i++)
    {
        if (arr[i] == 0)
            continue;
        for (j = 2 * i; j <= M; j += i)
            arr[j] = 0;
    }

    for (i = N; i <= M; i++)
        if (arr[i] != 0)
            cout << arr[i] << "\n";

    return 0;
}