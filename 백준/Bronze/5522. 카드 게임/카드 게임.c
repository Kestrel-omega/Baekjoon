#include <stdio.h>
#include <math.h>

int main(void) 
{
    int ai[5];
    int sum = 0;
    
    for(int i = 0;i<5;i++)
    {
        scanf("%d",&ai[i]);
        sum += ai[i];
    }
    printf("%d\n",sum);
    return 0;
}