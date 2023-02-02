#include <stdio.h>

int main()
{
    int a, i, sum = 0;
    scanf("%d", &a);
    for(i = 1; i*i < a; i++) if(a % i == 0) sum += (i + a/i);
    if(i*i == a) sum += i;
    printf("%d", sum*5-24);
}