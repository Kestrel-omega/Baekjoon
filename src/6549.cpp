#include <iostream>
#include <stack>

using namespace std;

typedef long long int lli;

lli max(lli a, lli b)
{
    return a > b ? a : b;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    lli answer;
    stack<lli> area_stack;
    
    while(1)
    {
        int area_height[100001] { 0, };
        answer = 0;
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) cin >> area_height[i];

        for (int i = 0; i < N; i++)
        {
            while (!area_stack.empty() && area_height[area_stack.top()] > area_height[i])
            {
                lli height = area_height[area_stack.top()];
                area_stack.pop();
                int width = i;
                if (!area_stack.empty()) width = (i - area_stack.top() - 1);
                answer = max(answer, width * height);
            }
            area_stack.push(i);
        }

        while (!area_stack.empty())
        {
            lli height = area_height[area_stack.top()];
            area_stack.pop();
            int width = N;
            if (!area_stack.empty()) width = (N - area_stack.top() - 1);
            answer = max(answer, width * height);
        }

        cout << answer << '\n';
        stack<lli>().swap(area_stack);
    }

    return 0;
}