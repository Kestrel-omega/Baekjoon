#include <stdio.h>
#include <math.h>

int main(void) 
{
    int a,b;
    
    scanf("%d %d", &a, &b);
    if(a<b)
        printf("<");
    else if(a>b)
        printf(">");
    else if(a==b)
        printf("==");
    return 0;
}