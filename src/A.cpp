#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    if(N + M - 2 < K) cout << "YES\n";
    else
    {
        cout << "NO\n";
        return 0;
    }

    for(int i = 0; i < N-1; i++)
    {
        for(int j = 0; j < M; j++) cout << i+j+1 << " ";
        cout << "\n";
    }
    
    for(int i = 0; i < M; i++) cout << N + i << " ";
    
    return 0;
}