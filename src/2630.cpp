#include <iostream>

using namespace std;

int N, W = 0, B = 0;
int arr[128][128];

void divide(int N, int x, int y)
{
    int color = arr[x][y];
    bool flag = true;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (arr[i][j] != color)
            {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag)
    {
        if (color == 0) W++;
        else B++;
    }
    else
    {
        divide(N / 2, x, y);
        divide(N / 2, x + N / 2, y);
        divide(N / 2, x, y + N / 2);
        divide(N / 2, x + N / 2, y + N / 2);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cin >> arr[i][j];
    }
    
    divide(N, 0, 0);

    cout << W << '\n' << B << '\n';

    return 0;
}