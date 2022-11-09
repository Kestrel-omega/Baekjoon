#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    pair<int, int> length[6];

    cin >> K;

    for(int i = 0; i < 6; i++) cin >> length[i].second >> length[i].first;

    sort(length, length+6);
    for(int i = 0; i < 6; i++) cout << length[i].first << length[i].second << endl;
    
    return 0;
}