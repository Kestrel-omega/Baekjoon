#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    int N, M, count = 0;
    vector<int> sequence;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        sequence.push_back(num);
    }

    sort(sequence.begin(), sequence.end());

    do
    {
        count++;
        if(count == factorial[N-M])
        {
            count = 0;
            for (int i = 0; i < M; i++) cout << sequence[i] << " "; 
            cout << "\n";
        }
        
    } while (next_permutation(sequence.begin(), sequence.end()));
    
    return 0;
}