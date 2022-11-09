#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << N/5 + N/25 + N/125;
    
    return 0;
}