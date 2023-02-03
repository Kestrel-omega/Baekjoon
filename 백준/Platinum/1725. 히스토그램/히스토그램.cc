#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, area[100001], answer = 0;
    stack<int> area_stack;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> area[i];

    for (int i = 0; i < N; i++)
    {
        while (!area_stack.empty() && area[area_stack.top()] > area[i])
        {
            int height = area[area_stack.top()];
            area_stack.pop();
            int width = i;
            if (!area_stack.empty()) width = (i - area_stack.top() - 1);
            answer = max(answer, width * height);
        }
        area_stack.push(i);
    }

    while (!area_stack.empty())
    {
        int height = area[area_stack.top()];
        area_stack.pop();
        int width = N;
        if (!area_stack.empty()) width = (N - area_stack.top() - 1);
        answer = max(answer, width * height);
    }

    cout << answer << '\n';
    
    return 0;
}

// 출처: https://www.acmicpc.net/blog/view/12