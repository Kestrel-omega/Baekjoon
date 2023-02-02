#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int count = 0;
    vector<int> A;
    
    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        A.push_back(temp);
    }

    for(int i = N-1; i >= 0; i--)
    {
        int divided = (K / A[i]);
        if(K == 0) break;
        else if(divided > 0) 
        {
            count = count + divided;
            K -= (A[i] * divided);
        }

    }

    cout << count << endl;

    return 0;
}