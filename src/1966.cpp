#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;
    cin >> T;

    while(T--)
    {
        cin >> N >> M;
        vector<int> q;
        while(N--)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        int mem_document = q[M];
        sort(q.begin(), q.end());

        
    }
    
    return 0;
}