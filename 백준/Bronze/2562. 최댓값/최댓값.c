#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n;
    int arr[9];
    int max = 0;
    
    for(int i=0;i<9;i++)
    {
        scanf("%d", &arr[i]);
        if(max < arr[i])
        {
            max = arr[i];
            n=i+1;
        }
    }
    printf("%d %d",max,n);
    
    return 0;
}