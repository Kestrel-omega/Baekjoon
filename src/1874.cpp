#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    vector<char> operators;

    int count = 1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;

        while (count <= data)
        {
            s.push(count);
            operators.push_back('+');
            count++;
        }

        if (s.top() == data)
        {
            s.pop();
            operators.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < operators.size(); i++)
    {
        cout << operators[i] << "\n";
    }

    return 0;
}