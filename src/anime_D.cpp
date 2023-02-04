#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, maximum = 0;
    priority_queue<int, vector<int>, greater<int>> length;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        length.push(temp);
    }

    

    while(M > 0)
    {
        int running_time = 0;
        for(int i = 0; i < K; i++) 
        {
            if(length.empty()) goto escape;
            running_time = length.top();

            // cout << "running_time: " << running_time << ", M : " << M << endl;
            if(running_time > M) break;

            length.pop();
            maximum++;
        }
        M -= running_time;
    }
escape:
    cout << maximum << endl;
    
    return 0;
}