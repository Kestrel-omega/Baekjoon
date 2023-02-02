#include <iostream>

using namespace std;

long long int fibonacci[91] = {0,};

int main() 
{
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for(int i = 2; i < 91; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

    int n;
    cin >> n;
    cout << fibonacci[n];
    
    return 0;
}