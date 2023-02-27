#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> step;
int dp_idx_left_right[100001][5][5] = {0,};

int move(int from, int to)
{
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;
}

int solve(int left, int right, int idx)
{
    if(idx == step.size()) return 0;
    if(dp_idx_left_right[idx][left][right] != 0) return dp_idx_left_right[idx][left][right];

    int result = 0;
    result = min(solve(step[idx], right, idx + 1) + move(left, step[idx]), solve(left, step[idx], idx + 1) + move(right, step[idx]));
    dp_idx_left_right[idx][left][right] = result;
    return result;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    while(1)
    {
        int n;
        cin >> n;
        if(n == 0) break;
        step.push_back(n);
    }

    result = min(solve(0, 0, 0), solve(0, 0, 0) + 2);

    cout << result << endl;
    
    return 0;
}