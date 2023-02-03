/**
 * Fermat's little theorem
 * nCk = n! / (k! * (n-k)!) = n! / (k! * (n-k)!) % P
 * B^(P-1) = B*B^(P-2) = 1 (mod P)
 * AB^(-1)%P = AB^(P-2)%P = (A%P)(B^(P-2)%P)%P
 *
 * --> nCk % P = (n*(n-1)*...*(n-k+1) / k!) % P = n*(n-1)*...*(n-k+1) * (k!)^(P-2) % P
 * 
 * n*(n-1)*...*(n-k+1) / k!는 구하고
 * (k!)^(P-2) = k!^(mod-2)는 분할정복으로 구한다.
 **/

#include <iostream>

using namespace std;

typedef long long int lli;

const lli mod = 1000000007;
lli N, K;

lli pow(lli a, lli b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    lli temp = pow(a, b / 2);
    temp = (temp * temp) % mod;
    if (b % 2 == 0) return temp;
    else return (temp * a) % mod;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli ans = 1;

    cin >> N >> K;
    
    if (N == K || K == 0)
    {
        cout << 1;
        return 0;
    }

    for (lli i = N; i > N - K; i--) ans = (ans * i) % mod;
    for (lli i = 1; i <= K; i++) ans = (ans * pow(i, mod - 2)) % mod;

    cout << ans;
    
    return 0;
}