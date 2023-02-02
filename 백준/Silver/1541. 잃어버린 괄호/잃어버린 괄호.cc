#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string expression, temp_str = "";
    int sum = 0;
    bool is_negative = false;
    cin >> expression;

    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
            temp_str += expression[i];
        else
        {
            if (!temp_str.empty())
            {
                if (is_negative) sum -= stoi(temp_str);
                else sum += stoi(temp_str);
                temp_str = "";
            }
            if (expression[i] == '-') is_negative = true;
        }
    }

    if (!temp_str.empty())
    {
        if (is_negative) sum -= stoi(temp_str);
        else sum += stoi(temp_str);
    }

    cout << sum;

    return 0;
}