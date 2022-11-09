#include <stdio.h>
#include <string.h>

int main()
{
    char array[101];
    int uppercase, lowercase, space, number, length;

    while (gets(array) != '\0')
    {
        length = strlen(array);
        uppercase = 0;
        lowercase = 0;
        space = 0;
        number = 0;

        for (int j = 0; j < length; j++)
        {
            if (array[j] >= 'A' && array[j] <= 'Z')
                uppercase++;
            else if (array[j] >= 'a' && array[j] <= 'z')
                lowercase++;
            else if (array[j] == ' ')
                space++;
            else if (array[j] >= '0' && array[j] <= '9')
                number++;
        }
        printf("%d %d %d %d\n", lowercase, uppercase, number, space);
    }

    return 0;
}
