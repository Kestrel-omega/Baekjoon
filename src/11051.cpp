#include <iostream>

using namespace std;

int binomial_coefficient(int N, int K)
{
    int result;
    if(K == 0 || K == N)
        result = 1;
    else
        result = binomial_coefficient(N - 1, K - 1) + binomial_coefficient(N - 1, K);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i < 11; i++)
    {
        for(int j = 1; j < 2; j++)
        {
            printf("%dC%d = %d\n", i, j, binomial_coefficient(i,j));
        }
    }

    
    return 0;
}