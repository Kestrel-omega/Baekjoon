#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<long long int> distance;
    vector<long long int> cost;

    cin >> N;

    for(int i = 0; i < N-1; i++)
    {
        long long int temp;
        cin >> temp;
        distance.push_back(temp);
    }

    for(int i = 0; i < N; i++)
    {
        long long int temp;
        cin >> temp;
        cost.push_back(temp);
    }

    long long int min = cost[0];
    long long int sum = 0;

    for(int i = 0; i < N-1; i++)
    {
        if(min > cost[i])
        {
            min = cost[i];
        }
        sum += min * distance[i];
    }

    cout << sum << endl;

    return 0;
}