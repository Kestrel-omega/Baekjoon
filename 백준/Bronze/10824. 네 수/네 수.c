#include <stdio.h>

int main()
{
    char array[101];
    long long A, B, C, D, AB, CD;

    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);

    sprintf(array, "%lld%lld %lld%lld", A, B, C, D);
    sscanf(array, "%lld %lld", &AB, &CD);

    printf("%lld", AB+CD);

    return 0;
}
