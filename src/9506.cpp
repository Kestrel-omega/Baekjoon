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

    int N;
    cin >> N;

    while (N != -1)
    {
        vector<int> measure;
        int sum = 0;

        for (int i = 1; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                measure.push_back(i);
                if (i != N / i) measure.push_back(N / i);
            }
        }

        sort(measure.begin(), measure.end());
        for(int i : measure) sum += i;

        if (sum - N == N)
        {
            cout << N << " = ";
            for (int i = 0; i < measure.size() - 2; i++)
            {
                cout << measure[i] << " + ";
            }
            cout << measure[measure.size() - 2] << "\n";
        }
        else cout << N << " is NOT perfect.\n";

        cin >> N;
    }

    return 0;
}