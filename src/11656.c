#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Quick Sort (출처 : https://dojang.io/mod/page/view.php?id=638)

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    char S[1001] = {0};
    char S_list[1001][1001] = {0};

    int length;
    
    scanf("%s", &S);
    length = strlen(S);

    for(int i = 0; i < length; i++)
    {
        for(int j = i ; j < length ; j++)
            S_list[i][j-i] = S[j];
    }

    qsort(S_list, (size_t)length, sizeof(char)*1001, compare);

    for(int i = 0; i < length; i++)
        printf("%s\n", S_list[i]);

    return 0;
}
