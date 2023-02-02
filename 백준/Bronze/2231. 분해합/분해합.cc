#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);

    for(int i = 1; i < N; i++)
    {
        int sum = i;
        int iter = i;

        while(iter > 0)
        {
            sum += iter % 10;
            iter /= 10;
        }

        if(sum == N)
        {
            printf("%d", i);
            return 0;
        }
    }
    
    printf("0");
    return 0;
}