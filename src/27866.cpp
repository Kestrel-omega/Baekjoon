#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    char str[1001];
    cin >> str >> i;

    cout << str[i-1];
    
    return 0;
}