#include <iostream>

using namespace std;

int N;
int stat[20][20];
int answer = 1000000000;
bool visited[20];

void dfs(int count, int next_val)
{
    if (count == N / 2)
    {
        int start = 0;
        int link = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i] && visited[j]) start += stat[i][j];
                else if (!visited[i] && !visited[j]) link += stat[i][j];
            }
        }

        if (answer > abs(start - link)) answer = abs(start - link);
        return;
    }
    for (int i = next_val; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(count + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> stat[i][j];
        }
    }

    dfs(0, 0);

    cout << answer << '\n';
    
    return 0;
}