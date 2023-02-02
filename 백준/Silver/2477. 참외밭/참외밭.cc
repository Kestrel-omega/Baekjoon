#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, direction, length;
    int east_west = 0;
    int north_south = 0;
    int index = -1;
    bool check = false;
    vector<pair<int, int>> direction_length;

    cin >> K;
    
    for (int i = 0; i < 6; i++)
    {
        cin >> direction >> length;

        direction_length.push_back(make_pair(direction, length));
        if (direction >= 3) north_south += length;
        else east_west += length;
    }

    north_south /= 2;
    east_west /= 2;

    for (int i = 0; i < 6; i++)
    {
        if (direction_length[i].second == north_south || direction_length[i].second == east_west)
        {
            int k = i + 1;
            if (k > 5) k = 0;
            if (direction_length[k].second == north_south || direction_length[k].second == east_west)
            {
                index = k;
                break;
            }
        }
    }

    int x = index + 2;
    int y = index + 3;

    if (x > 5) x -= 6;
    if (y > 5) y -= 6;

    cout << ((north_south * east_west) - (direction_length[x].second * direction_length[y].second)) * K << "\n";
}
