#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, arr[1001], answer = 1;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    for(int i = 0; i < N; i++)
    {
        if(answer < arr[i]) break;
        answer += arr[i];
    }

    cout << answer << "\n";
    
    return 0;
}