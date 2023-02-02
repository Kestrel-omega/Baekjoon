#include <iostream>

using namespace std;

long long int fibonacci_arr[51] = {0, 1, };

void make_fibonacci(void)
{
    for(int i = 2; i < 51; i++)
    {
        fibonacci_arr[i] = fibonacci_arr[i-1] + fibonacci_arr[i-2];
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    make_fibonacci();

    int T, N;

    cin >> T;

    while(T--)
    {
        cin >> N;

        if(N == 0) cout << "1 0\n";
        else cout << fibonacci_arr[N-1] << " " << fibonacci_arr[N] << endl;
    }

    return 0;
}