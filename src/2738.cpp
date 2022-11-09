#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int arr1[101][101], arr2[101][101];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << arr1[i][j]+arr2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}