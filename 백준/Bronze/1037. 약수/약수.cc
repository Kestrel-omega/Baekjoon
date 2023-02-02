#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> A;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    sort(A.begin(), A.end());

    cout << A[0] * A[N-1] << endl;

    
    return 0;
}