#include <iostream>
using namespace std;

int main()
{
    int T, k, n, i;
    cin >> T;
    int arr[15][14] = { 0, };
    for (i = 0;i < 15;i++)
        arr[i][0] = 1;
    for (i = 0;i < 14;i++)
        arr[0][i] = 1 + i;
    for (i = 1;i < 15;i++)
    {
        for (int j = 1;j < 14;j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }

    for (i = 0;i < T;i++)
    {
        cin >> k >> n;
        cout << arr[k][n - 1] << endl;
    }
    return 0;
}