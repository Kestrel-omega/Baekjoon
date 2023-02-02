#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n, m, k;
    
    scanf("%d %d %d", &n, &m, &k);
    printf("%d %d", k/m, k%m);
    return 0;
}