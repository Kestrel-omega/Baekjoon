#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1000001] = {0, 1, 2,};

    int N;
    cin >> N;

    for(int i = 3; i <= N; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }

    cout << arr[N];
    
    return 0;
}