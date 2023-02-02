#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int index, int count, int N, int M, vector<int> sequence, int* selected)
{
    if(count == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = index; i < N; i++)
    {
        selected[count] = sequence[i];
        dfs(i, count + 1, N, M, sequence, selected);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> sequence;
    int N, M;

    cin >> N >> M;

    int* selected = new int[M];

    for(int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        sequence.push_back(temp);
    }

    sort(sequence.begin(), sequence.end());

    dfs(0, 0, N, M, sequence, selected);

    return 0;
}