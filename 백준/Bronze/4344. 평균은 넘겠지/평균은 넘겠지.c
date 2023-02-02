#include <stdio.h> 
int main() 
{ 
    int c = 0, n = 0;
    scanf("%d", &c);
    while (c--) 
    { 
        scanf("%d", &n);
        int score[1000];
        int sum = 0;
        double avg = .0;
        for (int i = 0; i < n; i++) 
        { 
            scanf("%d", &score[i]);
            sum += score[i];
        } 
        avg = (double)sum / n; 
        int count = 0; 
        for (int i = 0; i < n; i++) 
        { 
            if (avg < score[i]) 
            { 
                count++;
            }
        } 
        printf("%.3f%%\n", (double)count * 100 / n); 
        
    } 
    return 0; 
    
}
