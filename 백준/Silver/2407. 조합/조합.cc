#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add_big_num(string a, string b)
{
    string result;
    int sum = 0;
    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string combination[101][101];
    combination[0][0] = "1";
    combination[1][0] = "1";
    combination[1][1] = "1";

    cin >> n >> m;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(j == 0 || j == i) combination[i][j] = "1";
            else combination[i][j] = add_big_num(combination[i - 1][j - 1], combination[i - 1][j]);
        }
    }

    cout << combination[n][m];
    
    return 0;
}