#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> sequence;
    vector<bool> is_selected;
    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) sequence.push_back(i);

    for (int i = 0; i < M; i++) is_selected.push_back(true);
    for (int i = M; i < N; i++) is_selected.push_back(false);

    do
    {
        for (int i = 0; i < N; i++)
        {
            if (is_selected[i]) cout << sequence[i] << " ";
        }
        cout << "\n";
    } while (prev_permutation(is_selected.begin(), is_selected.end()));

    cin >> N >> M;

    return 0;
}