#include <iostream>
#include <string.h>

using namespace std;

int recursion_count = 0;

int recursion(const char s[], int l, int r)
{
    recursion_count++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char s[])
{
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    char S[1001];

    cin >> T;

    while (T--)
    {
        recursion_count = 0;
        cin >> S;
        int palindrone_return = isPalindrome(S);

        printf("%d %d\n", palindrone_return, recursion_count);
    }

    return 0;
}