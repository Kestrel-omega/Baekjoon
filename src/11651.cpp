#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<pair<int, int>> coord;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> b >> a;

        coord.push_back(pair<int, int>(a, b));
    }
    sort(coord.begin(), coord.end());

    vector<pair<int, int>>::iterator i;

    for (i = coord.begin(); i != coord.end(); i++)
    {
        cout << i->second << " " << i->first << "\n";
    }
    return 0;
}
