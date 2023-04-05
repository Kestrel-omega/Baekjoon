#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long min, max;
    long long count = 0;
    
    cin >> min >> max;
    long long size = max - min + 1;
    vector<bool> isSquare(size, true);
    
    for (long long i = 2; i * i <= max; i++)
    {
        long long square = i * i;
        long long start = min / square;
        if (min % square != 0) start++;
        for (long long j = start; j * square <= max; j++)
        {
            if (isSquare[j * square - min])
            {
                isSquare[j * square - min] = false;
                count++;
            }
        }
    }

    cout << size - count;
    return 0;
}