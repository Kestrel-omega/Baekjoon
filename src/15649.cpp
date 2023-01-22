#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int idx_divider[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> sequence;
    int N, M;
    int cursor = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) sequence.push_back(i);

    do
    {
        if(cursor % idx_divider[N-M] == 0)
        {
            for (int i = 0; i < M; i++) cout << sequence[i] << " ";
            cout << "\n";
        }
        cursor++;
    } 
    while (next_permutation(sequence.begin(), sequence.end()));

    return 0;
}