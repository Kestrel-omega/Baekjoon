#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    vector<int> measure;

    cin >> N >> K;

    for(int i = 1; i <= sqrt(N); i++)
    {
        if(N % i == 0)
        {
            measure.push_back(i);
            if(i != N / i) measure.push_back(N / i);
        }
    }

    sort(measure.begin(), measure.end());

    if(measure.size() < K) cout << "0";
    else cout << measure[K - 1];

    return 0;
}