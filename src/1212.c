#include <stdio.h>
#include <string.h>

int main()
{
    char oct[333335];
    int value[8] = {0, 1, 10, 11, 100, 101, 110, 111};
    scanf("%s", &oct);

    printf("%d", value[oct[0] - '0']);
    for (int i = 1; oct[i]; i++)
    {
        printf("%03d", value[oct[i] - '0']);
    }
    printf("\n");
    return 0;
}
