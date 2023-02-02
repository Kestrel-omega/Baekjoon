#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<int> card;

    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        int temp;
        cin >> temp;
        card.push_back(temp);
    }

    sort(card.begin(), card.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int number;
        cin >> number;
        vector<int>::iterator low = lower_bound(card.begin(), card.end(), number);
        vector<int>::iterator high = upper_bound(card.begin(), card.end(), number);
        cout << high - low << ' ';
    }

    return 0;
}