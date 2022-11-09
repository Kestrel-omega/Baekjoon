#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= i; j++) 
        cout << "*";
        printf("\n");
    }

    return 0;
}
