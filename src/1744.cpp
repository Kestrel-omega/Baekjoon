#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum = 0, ones = 0;
    priority_queue<int> positive;
    priority_queue<int, vector<int>, greater<int>> negative;
    queue<int> zero;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (temp > 1) positive.push(temp);
        else if (temp == 1) ones++;
        else if(temp < 0) negative.push(temp);
        else zero.push(temp);
    }

    while (!positive.empty())
    {
        int temp = positive.top();
        positive.pop();
        if (positive.empty()) sum += temp;
        else
        {
            sum += temp * positive.top();
            positive.pop();
        }
    }

    while (!negative.empty())
    {
        int temp = negative.top();
        negative.pop();
        if (negative.empty())
        {
            if (zero.size()) zero.pop();
            else sum += temp;
        }
        else
        {
            sum += temp * negative.top();
            negative.pop();
        }
    }

    sum += ones;

    cout << sum << endl;
    
    return 0;
}