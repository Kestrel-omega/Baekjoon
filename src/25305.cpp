#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;
    vector<int> score;

    cin >> N >> k;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        score.push_back(x);
    }

    sort(score.begin(), score.end());
    cout << score[N-k] << endl;
    
    return 0;
}