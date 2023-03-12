#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, W;
vector<pair<int, int>> p;
int store[1001][1001];
int police_store[1001][1001];

int calc_dist(int police, int target, int start)
{
    int p_x, p_y, t_x, t_y;
    
    if (start == 1)
    {
        p_x = 1;
        p_y = 1;
    }
    else if (start == 2)
    {
        p_x = N;
        p_y = N;
    }
    else
    {
        p_x = p[police - 1].first;
        p_y = p[police - 1].second;
    }

    t_x = p[target - 1].first;
    t_y = p[target - 1].second;

    return abs(p_x - t_x) + abs(p_y - t_y);
}

int find_dist(int police_1, int police_2)
{
    if (police_1 == W || police_2 == W) return 0;

    int temp_1, temp_2, move;

    move = max(police_1, police_2) + 1;
    if (store[police_1][police_2] != -1) return store[police_1][police_2];

    if (police_1 == 0) temp_1 = find_dist(move, police_2) + calc_dist(police_1, move, 1);
    else temp_1 = find_dist(move, police_2) + calc_dist(police_1, move, 0);

    if (police_2 == 0) temp_2 = find_dist(police_1, move) + calc_dist(police_2, move, 2);
    else temp_2 = find_dist(police_1, move) + calc_dist(police_2, move, 0);

    store[police_1][police_2] = min(temp_1, temp_2);

    if (temp_1 < temp_2) police_store[police_1][police_2] = 1;
    else police_store[police_1][police_2] = 2;

    return min(temp_1, temp_2);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    int y;

    cin >> N >> W;

    for (int i = 0; i < W; i++)
    {
        cin >> x;
        cin >> y;
        p.push_back(make_pair(x, y));
    }

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            store[i][j] = -1;
            police_store[i][j] = -1;
        }
    }

    cout << find_dist(0, 0) << endl;

    x = 0;
    y = 0;

    for (int i = 0; i < W; i++)
    {
        cout << police_store[x][y] << endl;
        if (police_store[x][y] == 1) x = i + 1;
        else y = i + 1;
    }

    return 0;
}