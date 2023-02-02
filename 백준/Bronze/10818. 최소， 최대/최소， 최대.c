#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int min = -1000001;
    int max = 1000001;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        if(min < arr[i])
            min = arr[i];
        if(max > arr[i])
            max = arr[i];
    }
    printf("%d %d",max,min);
}