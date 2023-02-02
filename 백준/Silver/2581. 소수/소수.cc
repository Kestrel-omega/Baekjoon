#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int M, N, i, j, sum=0;
    cin >> N >> M;

    int arr[10001] = { 0, };;

    for (i = N;i <= M;i++)
        arr[i] = i;
    arr[1] = 0;

    for (i = 2;i <= M;i++)
    {
        for (j = N;j <= M;j++)
        {
            if(arr[j]!=i&&arr[j]%i==0)
                arr[j]=0;
        }
    }

    for (i = N;i <= M;i++)
    {
        if (arr[i] != 0)
            sum += arr[i];
    }
    if (sum == 0)
    {
        cout << "-1";
        return 0;
    }
    cout << sum << endl;
    
    for (i = N;i <= M;i++)
    {
        if (arr[i] != 0)
        {
            cout << arr[i];
            break;
        }
    }
    return 0;
}