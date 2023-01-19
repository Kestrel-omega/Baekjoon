#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    long long int count[1001] = {0,};
    long long int sum = 0;
    long long int answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        count[sum % M]++;
    }

    for (int i = 0; i <= 1000; i++)
    {
        answer += count[i] * (count[i] - 1) / 2;
    }

    cout << count[0] + answer;

    return 0;
}