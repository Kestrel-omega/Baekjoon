#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 16777216;

int N, K;
int position[1000001];
queue<int> time_position;

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
        int current = time_position.front();
        time_position.pop();

        if(current == K) 
        {
            cout << position[current] << "\n";
            break;
        }

        if(current * 2 <= 100000 && position[current * 2] > position[current])
        {
            position[current * 2] = position[current];
            time_position.push(current * 2);
        }

        if(current + 1 <= 100000 && position[current + 1] > position[current] + 1)
        {
            position[current + 1] = position[current] + 1;
            time_position.push(current + 1);
        }

        if(current - 1 >= 0 && position[current - 1] > position[current] + 1)
        {
            position[current - 1] = position[current] + 1;
            time_position.push(current - 1);
        }
    }
    
    return 0;
}