#include <iostream>

using namespace std;

void queen(int x, int n, int col[], int &ans)
{
    if (n == x) ans++;
    else
    {
        for (int i = 0; i < n; i++)
        {
            col[x] = i;
            bool is_crash = true;
            for (int j = 0; j < x; j++)
            { 
                if (col[x] == col[j] || abs(col[x] - col[j]) == x - j) 
                {
                    is_crash = false;
                    break;
                }
            }
            if (is_crash) queen(x + 1, n, col, ans);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int col[16];
    int n;
    int ans = 0;

    cin >> n;
    queen(0, n, col, ans);
    cout << ans;
    return 0;
}