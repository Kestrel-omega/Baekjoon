#include <stdio.h>
#include <string.h>

int main()
{
    char S[101];
    int length;
    gets(S);
    length = (int)strlen(S);

    for (int i = 0; i < length; i++)
    {
        if (S[i] >= 'A' && S[i] <= 'A' + 12)
            printf("%c", S[i] + 13);
        else if (S[i] >= 'A' + 13 && S[i] <= 'A' + 25)
            printf("%c", S[i] - 13);
        else if (S[i] >= 'a' && S[i] <= 'a' + 12)
            printf("%c", S[i] + 13);
        else if (S[i] >= 'a' + 13 && S[i] <= 'a' + 25)
            printf("%c", S[i] - 13);
        else
            printf("%c", S[i]);
    }
    return 0;
}
