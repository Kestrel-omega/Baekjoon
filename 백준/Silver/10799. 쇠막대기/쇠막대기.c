#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char bracket[100001];

int main(void)
{
    int count = 0;
    int total = 0;

    scanf("%s", bracket);

    for (int i = 0; i < strlen(bracket); i++)
    {
        if (bracket[i] == '(')
        {
            count++;
        }
        else
        {
            count--;
            if (bracket[i - 1] != bracket[i]) // 레이저 커팅
                total += count;
            if (bracket[i] == bracket[i + 1]) // 파이프 추가
                total += 1;
        }
    }

    printf("%d\n", total);
}
