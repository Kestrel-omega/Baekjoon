#include <iostream>

using namespace std;

int A[11];
int N;
int min_result = 1000000000;
int max_result = -1000000000;

void dfs(int plus, int minus, int mul, int div, int idx, int sum)
{
    if (idx == N-1)
    {
        if (sum > max_result) max_result = sum;
        if (sum < min_result) min_result = sum;
    }

    if (plus > 0) dfs(plus - 1, minus, mul, div, idx + 1, sum + A[idx+1]);
    if (minus > 0) dfs(plus, minus - 1, mul, div, idx + 1, sum - A[idx+1]);
    if (mul > 0) dfs(plus, minus, mul - 1, div, idx + 1, sum * A[idx+1]);
    if (div > 0) dfs(plus, minus, mul, div - 1, idx + 1, sum / A[idx+1]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int op[4];
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> op[i];

    dfs(op[0], op[1], op[2], op[3], 0, A[0]);

    cout << max_result << "\n" << min_result;
    
    return 0;
}