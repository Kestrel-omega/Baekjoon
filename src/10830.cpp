#include <iostream>

using namespace std;

typedef long long int lli;

int N;
lli B;
lli A[5][5], answer[5][5];

void multiply(lli A[][5], lli B[][5])
{
    lli temp[5][5] = {0, };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++) temp[i][j] += A[i][k] * B[k][j];
            temp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) A[i][j] = temp[i][j];
    }
}

void power(lli A[][5], lli B)
{
    if (B == 1) 
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++) A[i][j] %= 1000;
        }
        return;
    }
    power(A, B / 2);
    multiply(A, A);

    if (B % 2 == 1) multiply(A, answer);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            answer[i][j] = A[i][j];
        }
    }

    power(A, B);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cout << A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}