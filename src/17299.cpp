#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int NGF[1000001] = {0, };
    int number[1000001] = {0, };
    int result[1000001] = {0, };
    stack<int> A;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
        NGF[number[i]]++;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        int num = number[i];
        int height = NGF[num];

        while (!A.empty())
        {
            int top_number = number[A.top()];
            int top_height = NGF[top_number];

            if (height >= top_height) A.pop();
            else break;
        }
        result[i] = -1;
        if (!A.empty()) result[i] = number[A.top()];

        A.push(i);
    }

    for (int i = 0; i < N; i++) cout << result[i] << " ";
    
    return 0;
}