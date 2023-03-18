#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrome[2501][2501];
string input;
int dp[2501];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    int len = input.length();

    for (int i = 0; i < len; i++) is_palindrome[i][i] = true;
    
    for (int i = 0; i < len - 1; i++)
    {
        if (input[i] == input[i + 1]) is_palindrome[i][i + 1] = true;
    }

    for (int i = 2; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            if (input[j] == input[j + i] && is_palindrome[j + 1][j + i - 1]) is_palindrome[j][j + i] = true;
        }
    }

    for (int i = 0; i < len; i++)
    {
        dp[i] = 2501;

        for (int j = 0; j <= i; j++)
        {
            if (is_palindrome[j][i])
            {
                if (j == 0) dp[i] = 1;
                else dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[len - 1];
   
    return 0;
}