#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible = false;
vector<int> cnt_vector;

void dfs(int A, int B, int cnt)
{
    if(A == B)
    {
        is_possible = true;
        cnt_vector.push_back(cnt);
        return;
    }
    if(A > B) return;
    dfs(A*2, B, cnt+1);
    dfs(A*10+1, B, cnt+1);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, cnt = 1, ret = 0;
    cin >> A >> B;
    
    dfs(A, B, cnt);

    if(is_possible)
    {
        sort(cnt_vector.begin(), cnt_vector.end());
        cout << cnt_vector[0];
    }
    else cout << -1;

    return 0;
}