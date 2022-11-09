#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int arr[500001];
    int check[8001] = {0,};
    int N, most;
    int max = -4000;
    int sum = 0;

    cin >> N;

    for(int i = 0; i<N; i++) 
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
        sum += temp;
        check[temp+4000]++;
    }

    sort(arr, arr+N);

    for(int i = 0; i < 8001; i++)
    {
        if(check[i] > max)
        {
            max = check[i];
            most = i;
        }
    }

    for(int i = most+1; i < 8001; i++)
    {
        if(check[i] == max)
        {
            most = i;
            break;
        }
    }

    // 산술평균
    if(round((float)sum / N) == -0) cout << "0\n";
    else cout << round((float)sum / N) << "\n";
    // 중앙값
    cout << arr[(N-1)/2] << "\n";
    // 최빈값
    cout << most - 4000 << "\n";
    // 범위
    cout << arr[N-1]-arr[0] << "\n";

    return 0;
}