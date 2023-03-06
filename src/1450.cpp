#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
long long backpack[31], answer = 0;
vector<long long> sum_left, sum_right;

// dfs 함수를 이용하여 왼쪽과 오른쪽으로 나누어서 각각의 부분집합의 합 구함

void left(long long sum, int idx)
{
    if (idx == N/2)
    {
        sum_left.push_back(sum);
        return;
    }
    left(sum, idx+1);
    left(sum + backpack[idx], idx+1);
}

void right(long long sum, int idx)
{
    if (idx == N)
    {
        sum_right.push_back(sum);
        return;
    }
    right(sum, idx+1);
    right(sum + backpack[idx], idx+1);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; i++) cin >> backpack[i];

    left(0, 0);
    right(0, N/2);

    sort(sum_right.begin(), sum_right.end());

    for (int i = 0; i < sum_left.size(); i++)
    {
        answer += upper_bound(sum_right.begin(), sum_right.end(), C - sum_left[i]) - sum_right.begin();
    }

    cout << answer;
    
    return 0;
}