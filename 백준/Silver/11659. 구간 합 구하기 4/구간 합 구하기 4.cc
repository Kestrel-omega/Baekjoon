#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    
    int* arr = new int[N+1];

    arr[0] = 0;

    for(int i = 1; i < N+1; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp + arr[i-1];
    }

    while(M--)
    {
        int i, j;
        int sum = 0;
        
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << "\n";
    }

    delete[] arr;
    
    return 0;
}