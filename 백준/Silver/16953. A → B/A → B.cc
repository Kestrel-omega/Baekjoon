#include <iostream>
#include <queue>

using namespace std;

typedef long long int lli;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<lli, lli>> q;
    lli A, B, cnt = 1, ret = 0;
    cin >> A >> B;
    
    q.push(make_pair(A, cnt));
    while (!q.empty())
    {
        lli num = q.front().first;
        lli cnt = q.front().second;
        q.pop();
        if (num == B)
        {
            ret = cnt;
            break;
        }
        if (num * 2 <= B) q.push(make_pair(num * 2, cnt + 1));
        if (num * 10 + 1 <= B) q.push(make_pair(num * 10 + 1, cnt + 1));
    }
    if (ret == 0) ret = -1;
    cout << ret << "\n";

    return 0;
}