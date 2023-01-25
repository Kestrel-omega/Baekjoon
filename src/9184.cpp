#include <iostream>

using namespace std;

int memory[21][21][21];

int function(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return 1048576;
    if(memory[a][b][c] != 0)
        return memory[a][b][c];
    if(a < b && b < c)
        return memory[a][b][c] = function(a, b, c - 1) + function(a, b - 1, c - 1) - function(a, b - 1, c);
    return memory[a][b][c] = function(a - 1, b, c) + function(a - 1, b - 1, c) + function(a - 1, b, c - 1) - function(a - 1, b - 1, c - 1);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    

    while(1)
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << function(a, b, c) << "\n";
    }
    
    return 0;
}