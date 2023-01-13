#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

int main()
{
    int n, first_ring;
    cin >> n >> first_ring;
    n--;

    while(n--)
    {
        int ring;
        cin >> ring;
        cout << first_ring / GCD(first_ring, ring) << "/" << ring / GCD(first_ring, ring) << endl;
    }

    return 0;
}