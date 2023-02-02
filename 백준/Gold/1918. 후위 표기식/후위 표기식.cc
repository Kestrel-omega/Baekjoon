#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> operators;
    string expression, result;

    getline(cin, expression);

    for(int i = 0; i < expression.length(); i++)
    {
        if(expression[i] >= 'A' && expression[i] <= 'Z')
            result += expression[i];
        else if(expression[i] == '(')
            operators.push(expression[i]);
        else if(expression[i] == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else if(expression[i] == '*' || expression[i] == '/')
        {
            while(!operators.empty() && (operators.top() == '*' || operators.top() == '/'))
            {
                result += operators.top();
                operators.pop();
            }
            operators.push(expression[i]);
        }
        else if(expression[i] == '+' || expression[i] == '-')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            operators.push(expression[i]);
        }
    }

    while(!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }

    cout << result << endl;
    
    return 0;
}