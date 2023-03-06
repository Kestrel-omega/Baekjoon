#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, answer = 0, sum = 0;
    int point_first = 0, point_second = 0; 
    cin >> N;
    vector<bool> is_prime(N+1, true);
    vector<int> prime;

    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i] == true)
        {
            for (int j = i * 2; j <= N; j += i) is_prime[j] = false;
        }
    }

    for(int i = 2; i <= N; i++) if (is_prime[i] == true) prime.push_back(i);

    while(point_first <= point_second)
    {
        if(sum > N)
        {
            sum -= prime[point_first];
            point_first++;
        }
        else 
        {
            if(sum == N) answer++;
            if(point_second == prime.size()) break;
            sum += prime[point_second];
            point_second++;
        }
    }

    cout << answer;

    return 0;
}