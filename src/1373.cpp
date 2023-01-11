#include <stdio.h>
#include <string.h>

char num[1000003] = {'0', '0'};

int main()
{
    scanf("%s", num + 2);

    int length = strlen(num);

    for (int i = length % 3; i < length; i = i + 3)
        printf("%d", (num[i] - '0') * 4 + (num[i + 1] - '0') * 2 + (num[i + 2] - '0'));

    return 0;
}
