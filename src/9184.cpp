#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    int arr[21][21][21] = {1,};

    while(1)
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;
        if(a <= 0 || b <= 0 || c <= 0)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
            continue;
        }
        if(a > 20 || b > 20 || c > 20)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1048576 << "\n";
            continue;
        }
        if(arr[a][b][c] != 0)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << "\n";
            continue;
        }
        if(a < b && b < c)
        {
            arr[a][b][c] = arr[a][b][c-1] + arr[a][b-1][c-1] - arr[a][b-1][c];
            cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << "\n";
            continue;
        }
        arr[a][b][c] = arr[a-1][b][c] + arr[a-1][b-1][c] + arr[a-1][b][c-1] - arr[a-1][b-1][c-1];
        cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << "\n";
    }
    
    return 0;
}