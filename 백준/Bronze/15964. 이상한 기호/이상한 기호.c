#include <stdio.h>
#include <math.h>

int main(void) 
{
    long long a,b;
    
    scanf("%lli %lli", &a, &b);
    printf("%lli", (a+b)*(a-b));
    return 0;
}