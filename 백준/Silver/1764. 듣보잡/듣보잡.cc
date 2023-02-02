#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<string> not_heard;
    vector<string> idk;

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        string name;
        cin >> name;
        not_heard.push_back(name);
    }

    sort(not_heard.begin(), not_heard.end());

    for (int i = 0; i < M; i++)
    {
        string not_seen;
        cin >> not_seen;
        if(binary_search(not_heard.begin(), not_heard.end(), not_seen)) idk.push_back(not_seen);
    }

    sort(idk.begin(), idk.end());

    cout << idk.size() << "\n";
    for(int i = 0; i < idk.size(); i++ ) cout << idk[i] << "\n";

    return 0;
}