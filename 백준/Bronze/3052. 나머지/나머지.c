#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n;
    int arr[42] = {0,};
    int sum = 0;
    
    for(int i=0;i<10;i++)
    {
        scanf("%d", &n);
        if(!arr[n%42]++)
            sum++;
    }
    printf("%d",sum);
    
    return 0;
}