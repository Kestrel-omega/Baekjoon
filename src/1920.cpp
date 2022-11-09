#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<int> answer_array;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        answer_array.push_back(input);
    }

    sort(answer_array.begin(), answer_array.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        cout << binary_search(answer_array.begin(), answer_array.end(), input) << '\n';
    }

    return 0;
}