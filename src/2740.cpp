#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    int A[100][100];
    int B[100][100];
    int ans[100][100] = {0, };

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }

    cin >> M >> K;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++) cin >> B[i][j];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < K; k++)
            {
                ans[i][k] += A[i][j] * B[j][k];
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}