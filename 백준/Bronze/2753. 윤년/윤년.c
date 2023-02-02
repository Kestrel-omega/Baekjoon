#include <stdio.h>
#include <math.h>

int main(void) 
{
    int a;
    
    scanf("%d", &a);
    if(a%4==0 && a%100!=0 || a%4==0 && a%400==0)
        printf("1");
    else
        printf("0");
    return 0;
}