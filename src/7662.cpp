#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;

        multiset<int> s;

        while (k--)
        {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') s.insert(n);
            else if (c == 'D')
            {
                if (s.empty()) continue;
                if (n == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }

        if (s.empty()) cout << "EMPTY\n";
        else cout << *--s.end() << ' ' << *s.begin() << ' ';
    }

    return 0;
}