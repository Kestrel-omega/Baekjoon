#include <stdio.h>
#include <string.h>
int main()
{
    int alphabet[26];
    char array[100];
    scanf("%s", array);

    for (int i = 0; i < 26; i++)
        alphabet[i] = -1;
    for (int i = 'a'; i <= 'z'; i++)
    {
        for (int j = 0; j < strlen(array); j++)
        {
            if (array[j] == i)
            {
                alphabet[array[j] - 'a'] = j;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++)
        printf("%d ", alphabet[i]);
        
    return 0;
}
