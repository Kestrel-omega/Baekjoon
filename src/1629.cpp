#include <iostream>

using namespace std;

long long int pow(int A, int B, int C)
{
    if (B == 0) return 1;
    else if (B == 1) return A % C;
    else
    {
        long long int temp = pow(A, B / 2, C);
        if (B % 2 == 0) return (temp * temp) % C;
        else return (((temp * temp) % C) * A) % C;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;
    cout << pow(A, B, C);
    
    return 0;
}