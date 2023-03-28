#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in, post, present;

void preorder(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end) return;
    int root = post[post_end];
    cout << root << ' ';
    int p = present[root];
    int left = p - in_start;
    int right = in_end - p;
    preorder(in_start, p - 1, post_start, post_start + left - 1);
    preorder(p + 1, in_end, post_end - right, post_end - 1);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    in.resize(n + 1);
    post.resize(n + 1);
    present.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> in[i];
        present[in[i]] = i;
    }

    for (int i = 1; i <= n; i++) cin >> post[i];
    preorder(1, n, 1, n);

    return 0;
}