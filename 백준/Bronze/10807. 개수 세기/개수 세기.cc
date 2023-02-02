#include <iostream>

using namespace std;

int main()
{
    int N, v, arr[100];
    int count = 0;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cin >> v;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] == v) count++;
    }
    cout << count;
    return 0;
}