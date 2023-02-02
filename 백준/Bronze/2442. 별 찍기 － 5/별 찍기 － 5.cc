#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num = 0;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = num - i-1; j > 0; j--)
            printf(" ");
        for (int k = 1; k <= 2 * i + 1; k++)
            printf("*");
        printf("\n");
    }

    return 0;
}
