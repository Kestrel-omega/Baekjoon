#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long count = 0;
    stack<pair<int, int>> height_serial;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int height;
        cin >> height;

        while(!height_serial.empty() && height_serial.top().first < height)
        {
            count += height_serial.top().second;
            height_serial.pop();
        }

        if(height_serial.empty()) height_serial.push(make_pair(height, 1));
        else
        {
            if(height_serial.top().first == height)
            {
                pair<int, int> temp = height_serial.top();
                height_serial.pop();
                count += temp.second;
                if(!height_serial.empty()) count++;
                temp.second++;
                height_serial.push(temp);
            }
            else
            {
                height_serial.push(make_pair(height, 1));
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}