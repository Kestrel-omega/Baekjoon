#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int i;
        string sentence;
        stack<char> bracket;
        bool finish_flag = true;

        getline(cin, sentence);

        if (sentence == ".") break;

        for (i = 0; i < sentence.length(); i++)
        {
            char c = sentence[i];

            if ((c == '(') || (c == '['))
                bracket.push(c);
            else if (c == ')')
            {
                if (!bracket.empty() && bracket.top() == '(')
                    bracket.pop();
                else
                {
                    finish_flag = false;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!bracket.empty() && bracket.top() == '[')
                    bracket.pop();
                else
                {
                    finish_flag = false;
                    break;
                }
            }
        }

        if (finish_flag == true && bracket.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}