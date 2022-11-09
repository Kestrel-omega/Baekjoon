#include <stdio.h>

int main()
{
    int croatia = 0;
    char str[101];
    int i = 0;

    scanf("%s", str);
    while (str[i] != '\0')
    {
        croatia++;
        if (str[i] == '-')
        {
            if (str[i - 1] == 'c' || str[i - 1] == 'd') croatia--;
        }
        else if (str[i] == '=')
        {
            if (str[i - 1] == 'c' || str[i - 1] == 's') croatia--;
            else if (str[i - 1] == 'z')
            {
                croatia--;
                if (str[i - 2] == 'd') croatia--;
            }
        }

        else if (str[i] == 'j')
        {
            if (str[i - 1] == 'l' || str[i - 1] == 'n') croatia--;
        }
        i++;
    }

    printf("%d", croatia);

    return 0;
}