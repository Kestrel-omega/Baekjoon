#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    for(int i = 1; i <= num; i++)
    {
        for(int j = num; j > i; j--) 
            cout << " ";
        for(int k = 1; k <= i; k++) 
            cout << "*";
        printf("\n");
    }

    return 0;
}
