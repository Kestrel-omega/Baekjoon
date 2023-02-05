#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, max = 0;
    int left = 0, mid;
    vector<int> tree;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }

    int right = *max_element(tree.begin(), tree.end());

    while(left <= right)
    {
        mid = (left + right) / 2;
        long long sum = 0;

        for(int i = 0; i < N; i++) if(tree[i] > mid) sum += tree[i] - mid;

        if(sum >= M)
        {
            if(max < mid) max = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << max;

    return 0;
}