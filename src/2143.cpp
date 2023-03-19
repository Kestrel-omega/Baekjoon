#include <iostream>
#include <algorithm>
#include <vector>

int T, N, M;
int A[1001], B[1001];

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<int> sum_A, sum_B;

    for (int i = 0; i < N; i++)
    {
        int sum = A[i];
        sum_A.push_back(sum);
        for (int j = i+1; j < N; j++)
        {
            sum += A[j];
            sum_A.push_back(sum);
        }
    }

    for (int i = 0; i < M; i++)
    {
        int sum = B[i];
        sum_B.push_back(sum);
        for (int j = i+1; j < M; j++)
        {
            sum += B[j];
            sum_B.push_back(sum);
        }
    }

    sort(sum_B.begin(), sum_B.end());

    long long answer = 0;

    for (int i = 0; i < sum_A.size(); i++) 
    {
		int cur = T - sum_A[i];
		int left = lower_bound(sum_B.begin(), sum_B.end(), cur) - sum_B.begin();
		int right = upper_bound(sum_B.begin(), sum_B.end(), cur) - sum_B.begin();
		answer += (right - left);
	}

    cout << answer;

    return 0;
}