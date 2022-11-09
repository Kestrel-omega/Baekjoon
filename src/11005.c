#include <stdio.h>

int main()
{
    int num, notation, temp;

    scanf("%d%d", &num, &notation);

    while (num > 1)
    {
        temp = num % notation;
        num = num / notation;
        if (temp > 9 && notation > 10)
            printf("%c", 'A' + temp - 10);
        else
            printf("%d", temp);
    }
    return 0;
}
