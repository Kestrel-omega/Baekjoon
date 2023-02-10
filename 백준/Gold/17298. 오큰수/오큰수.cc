#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int NGE[1000001] = {0, };
    int result[1000001] = {0, };
    stack<int> A;

    cin >> N;

    for (int i = 0; i < N; i++) cin >> NGE[i];

    for (int i = N - 1; i >= 0; i--)
    {
        while (!A.empty() && A.top() <= NGE[i]) A.pop();

        if (A.empty()) result[i] = -1;
        else result[i] = A.top();

        A.push(NGE[i]);
    }

    for (int i = 0; i < N; i++) cout << result[i] << " ";
    
    return 0;
}