#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char num[40];
    int answer = 0;
    int digit, notation;
    scanf("%s %d", &num, &notation);
    int length = strlen(num);

    for (int i = 0; num[i]; i++)
    {
        if ('0' <= num[i] && num[i] <= '9')
            digit = num[i] - '0';
        else
            digit = num[i] + 10 - 'A';
        answer += (digit * (int)pow(notation, length-i-1));
    }

    printf("%d\n", answer);

    return 0;
}
