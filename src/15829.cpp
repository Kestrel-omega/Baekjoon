#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int hash = 0;
    long long int mod = 1234567891; // 서로소래요
    long long int share = 1;
    int L;

    cin >> L;

    char* word = new char[L];

    cin >> word;

    for(int i = 0; i < L; i++)
    {
        hash += (long long int)(((word[i]-('a'-1)) * share) % mod);
        share = (share * 31) % mod;

        // 출처 : https://velog.io/@lamknh/C-%EB%B0%B1%EC%A4%80-15829-Hashing
    }

    cout << hash << endl;
    
    return 0;
}