#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> origin, modified;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        origin.push_back(temp);

    }
    modified = origin;

    sort(modified.begin(), modified.end());
    modified.resize(unique(modified.begin(), modified.end()) - modified.begin());
    
    for(int i = 0; i < N; i++)
    {
        cout << lower_bound(modified.begin(), modified.end(), origin[i]) - modified.begin() << " ";
    }
    return 0;
}