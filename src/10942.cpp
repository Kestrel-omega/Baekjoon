#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, S, E;
bool is_palindrome[2001][2001];
int arr[2001];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) is_palindrome[i][i] = true;

    for (int i = 1; i < N; i++)
    {
        if (arr[i] == arr[i + 1]) is_palindrome[i][i + 1] = true;
    }

    for (int i = 2; i < N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (arr[j] == arr[j + i] && is_palindrome[j + 1][j + i - 1]) is_palindrome[j][j + i] = true;
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> S >> E;

        if (is_palindrome[S][E]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}