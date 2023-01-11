#include <stdio.h>

int main()
{
    int iter;
    scanf("%d", &iter);
    char PS[51];

    for (int j = 0; j < iter; j++)
    {
        scanf("%s", PS);
        int check = 0;
        for (int i = 0; i < strlen(PS); i++)
        {
            if (PS[i] == '(')
                check++;
            else
                check--;
            if (check < 0)
            {
                printf("NO\n");
                break;
            }
        }
        if (check == 0)
            printf("YES\n");
        else if (check > 0)
            printf("NO\n");
    }
    return 0;
}
