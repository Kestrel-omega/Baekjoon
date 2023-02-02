#include <iostream>

int main()
{
    int N, M;
    int card[101];
    int sum = 0;

    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        std::cin >> card[i];
    }
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i+1; j < N - 1; j++)
        {
            for (int k = j+1; k < N; k++)
            {
                if(card[i] + card[j] + card[k] >= sum && card[i] + card[j] + card[k] <= M) 
                {
                    sum = card[i] + card[j] + card[k];
                }
            }
        }
    }

    std::cout << sum;

    return 0;
}