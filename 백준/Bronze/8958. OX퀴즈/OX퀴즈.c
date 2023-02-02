#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n;
    char arr[100];
    scanf("%d", &n);
    
    for(int i=0;i<n;++i)
    {
        int score = 0;
        int combo = 0;
        scanf("%s", &arr);
        
        for(int j=0;j<strlen(arr);++j)
        {
            if(arr[j]=='O')
            {
                score += 1+combo;
                combo++;
            }
            else
                combo = 0;
        }
        printf("%d\n",score);
    }

    return 0;
}