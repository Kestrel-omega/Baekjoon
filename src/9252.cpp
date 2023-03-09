#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001] = {0,};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2, LCS;

    cin >> str1 >> str2;

    for(int i = 1; i <= str1.length(); i++)
    {
        for(int j = 1; j <= str2.length(); j++)
        {
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[str1.length()][str2.length()] << "\n";

    int i = str1.length(), j = str2.length();

    while(i > 0 && j > 0)
    {
        if(str1[i - 1] == str2[j - 1])
        {
            LCS += str1[i - 1];
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }

    for(int i = LCS.length() - 1; i >= 0; i--) cout << LCS[i];
    
    return 0;
}