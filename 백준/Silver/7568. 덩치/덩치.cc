#include <iostream>

using namespace std;

int main()
{
    int N, rank = 1;
    int weight[51] = {0,};
    int height[51] = {0,};

    cin >> N;

    for(int i = 0; i < N; i++) cin >> weight[i] >> height[i];

    for(int i = 0; i < N ; i++)
    {
        rank = 1;
        for(int j = 0; j < N; j++)
        {
            if(weight[i] < weight[j] && height[i] < height[j]) rank++;
        }
        cout << rank << " ";
    }
    return 0;
}