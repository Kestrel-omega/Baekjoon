#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, count = 0;
    vector<int> setA;
    vector<int> setB;

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;
        setA.push_back(num);
    }

    for (int i = 0; i < M; i++) 
    {
        int num;
        cin >> num;
        setB.push_back(num);
    }

    sort(setA.begin(), setA.end());
    sort(setB.begin(), setB.end());

    vector<int> setAuB_AnB(N+M);
    setAuB_AnB.erase(set_symmetric_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), setAuB_AnB.begin()), setAuB_AnB.end());

    cout << setAuB_AnB.size();

    return 0;
}