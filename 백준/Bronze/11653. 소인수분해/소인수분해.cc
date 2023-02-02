#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int N, i;
    cin >> N;
    int sN = sqrt(N);

    for (i = 2; i <= sN; i++) 
    {
        while (N % i == 0) 
        {
            cout << i << "\n";
            N /= i;
        }
    }

    if (N != 1) cout << N << "\n";

    return 0;
}