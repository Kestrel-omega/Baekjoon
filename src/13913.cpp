#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 16777216;

int N, K;
int position[1000001];
queue<int> time_position;
vector<int> path;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < 1000001; i++) position[i] = MAX;

    position[N] = 0;
    time_position.push(N);

    while(!time_position.empty())
    {
        int temp = time_position.front();
        time_position.pop();

        if(temp == K) break;

        if(temp - 1 >= 0 && position[temp - 1] > position[temp] + 1)
        {
            position[temp - 1] = position[temp] + 1;
            time_position.push(temp - 1);
        }
        if(temp + 1 <= 1000000 && position[temp + 1] > position[temp] + 1)
        {
            position[temp + 1] = position[temp] + 1;
            time_position.push(temp + 1);
        }
        if(temp * 2 <= 1000000 && position[temp * 2] > position[temp] + 1)
        {
            position[temp * 2] = position[temp] + 1;
            time_position.push(temp * 2);
        }
    }

    cout << position[K] << '\n';

    path.push_back(K);

    while(path.back() != N)
    {
        if(path.back() - 1 >= 0 && position[path.back() - 1] == position[path.back()] - 1) path.push_back(path.back() - 1);
        else if(path.back() + 1 <= 1000000 && position[path.back() + 1] == position[path.back()] - 1) path.push_back(path.back() + 1);
        else if(path.back() % 2 == 0 && position[path.back() / 2] == position[path.back()] - 1) path.push_back(path.back() / 2);
    }

    for(int i = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';

    return 0;
}