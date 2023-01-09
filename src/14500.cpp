#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

priority_queue<int> pq;
void f(int n, int m);
int a[505][505];

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    f(n, m);
    cout << pq.top() << "\n";
}
void f(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pq.push(a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3]); // case1
            pq.push(a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j]); // case2

            pq.push(a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1]); // case3

            pq.push(a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1]);         // case4
            pq.push(a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j]);             // case5
            pq.push(a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1]);     // case6
            pq.push(a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2]); // case7

            pq.push(a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1]); // case8
            pq.push(a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2]);         // case9
            pq.push(a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j]);             // case10
            pq.push(a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2]);     // case11

            pq.push(a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1]); // case12
            pq.push(a[i][j + 1] + a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1]); // case13

            pq.push(a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j]); // case14
            pq.push(a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2]); // case15

            pq.push(a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2]); // case16
            pq.push(a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j]);         // case17
            pq.push(a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]);         // case18
            pq.push(a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1]); // case19
        }
    }
    return;
}