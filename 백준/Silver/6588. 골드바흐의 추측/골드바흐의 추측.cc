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
    bool is_prime[1000001] = {false, };
    bool flag_prime = false;

    for(int i = 3; i <= 1000000; i += 2) {
        if(check_prime(i)) is_prime[i] = true;
    }

    while(true) {
        cin >> n;
        if(n == 0) break;

        flag_prime = false;
        for(int i = 3; i <= n; i += 2) {
            if(is_prime[i] && is_prime[n-i]) {
                cout << n << " = " << i << " + " << n-i << "\n";
                flag_prime = true;
                break;
            }
        }

        if(!flag_prime) cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
