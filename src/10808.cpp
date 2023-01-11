#include <stdio.h>

int main()
{
    char array[101];
    int i;
    int alphabet[26] = { 0 };
    
    scanf("%s", array);
    
    for (i = 0;i < strlen(array);i++)
        alphabet[array[i] - 'a']++;
    for (i=0; i<26; i++)
        printf("%d ", alphabet[i]);
    
    return 0;
}
