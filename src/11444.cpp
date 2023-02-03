#include <iostream>
#include <map>

using namespace std;

typedef long long int lli;

map<lli, lli> fib_number;
lli mod = 1000000007;

lli fib(lli n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (fib_number.find(n) != fib_number.end()) return fib_number[n];
    if (n % 2 == 0)
    {
        lli k = n / 2;
        lli a = fib(k - 1);
        lli b = fib(k);
        return fib_number[n] = ((2*a+b)*b) % mod;
    }
    else
    {
        lli k = (n + 1) / 2;
        lli a = fib(k - 1);
        lli b = fib(k);
        return fib_number[n] = (a * a + b * b) % mod;
    }    
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli N;
    cin >> N;
    cout << fib(N);
    
    return 0;
}