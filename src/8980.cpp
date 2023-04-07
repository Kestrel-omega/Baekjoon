#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct box_info
{
    int start;
    int end;
    int weight;
};

bool compare(box_info a, box_info b)
{
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C, M;
    int ans = 0;

    cin >> N >> C >> M;

    vector<box_info> send_receive(M);
    vector<int> truck(N + 1, C);

    for (int i = 0; i < M; i++)
    {
        cin >> send_receive[i].start >> send_receive[i].end >> send_receive[i].weight;
    }

    sort(send_receive.begin(), send_receive.end(), compare);

    for (int i = 0; i < M; i++)
    {
        int min_weight = C;
        for (int j = send_receive[i].start; j < send_receive[i].end; j++)
        {
            min_weight = min(min_weight, truck[j]);
        }

        int weight = min(min_weight, send_receive[i].weight);
        ans += weight;

        for (int j = send_receive[i].start; j < send_receive[i].end; j++)
        {
            truck[j] -= weight;
        }
    }

    cout << ans;

    return 0;
}