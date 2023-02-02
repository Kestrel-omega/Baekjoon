#include <iostream>
#include <vector>

using namespace std;

void dfs(int count, int M, vector<int> sequence, int* selected)
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

    for(int i = 0; i < sequence.size(); i++)
    {
        selected[count] = sequence[i];
        dfs(count + 1, M, sequence, selected);
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
        sequence.push_back(i);
    }

    dfs(0, M, sequence, selected);

    return 0;
}