#include <stdio.h>

int main()
{
    int N, temp;
    int arr[10000] = {0,};
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        arr[temp-1]++;
    }
    
    for(int i = 0; i < 10000; i++)
    {
        for(int j = 0; j < arr[i]; j++) printf("%d\n", i+1);
    }

    return 0;
}