#include <stdio.h>
#include <string.h>

int num[10001] = {-1, };

int main()
{
    int iter, element;
    int pointer = 0;
    char order[6];
    scanf("%d", &iter);
    while (iter)
    {
        scanf("%s", order);
        if (!strcmp(order, "push"))
        {
            scanf("%d", &element);
            num[pointer] = element;
            pointer++;
        }
        else if (!strcmp(order, "pop"))
        {
            if(pointer != 0)
            {
                pointer--;
                printf("%d\n", num[pointer]);
                num[pointer] = -1;
            }
            else
                printf("-1\n");
        }
        else if (!strcmp(order, "size"))
        {
            printf("%d\n", pointer);
        }
        else if (!strcmp(order, "empty"))
        {  
            if (pointer != 0)
                printf("0\n");
            else
                printf("1\n");
        }
        else // top
        {
            if (pointer != 0)
                printf("%d\n", num[pointer-1]);
            else
                printf("-1\n");
                
        }
        iter--;
    }

    return 0;
}
