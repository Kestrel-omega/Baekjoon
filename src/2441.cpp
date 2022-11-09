#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num = 0, a, b, c;

    cin >> num;

    for (a = 0; a < num; a++)
    {
        for (c = 0; c < a; c++)
            printf(" ");
        for (b = num; b > a; b--)
            printf("*");
        printf("\n");
    }
    
    return 0;
}