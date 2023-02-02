#include <iostream>

using namespace std;

bool check_prime(int n)
{
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++) if(n % i == 0) return false;
    
    return true;
}

int main()
{
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base :: sync_with_stdio(false);

    int a, b;
    int n = 1;
    bool flag_prime = false;

    while(n)
    {
        cin >> n;
        for(int i = 1; i < n/2; i++)
        {
            a = 2*i+1;
            b = n - a;

            if(check_prime(a) && check_prime(b))
            {
                cout << n << " = " << a << " + " << b << "\n";
                flag_prime = true;
                break;
            }
        }
        if(!flag_prime) cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
