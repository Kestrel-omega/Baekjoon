#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, arr[1000001], idx[1000001];
    vector<int> for_length, answer;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for(int i = 0; i < N; i++)
    {
        if(for_length.empty() || for_length.back() < arr[i])
        {
            for_length.push_back(arr[i]);
            idx[i] = for_length.size() - 1;
        }
        else
        {
            int pos = lower_bound(for_length.begin(), for_length.end(), arr[i]) - for_length.begin();
            for_length[pos] = arr[i];
            idx[i] = pos;
        }
    }
    cout << for_length.size() << '\n';
    int length = for_length.size() - 1;
    for(int i = N - 1; i >= 0; i--)
    {
        if(idx[i] == length)
        {
            answer.push_back(arr[i]);
            length--;
        }
    }
    for(int i = answer.size() - 1; i >= 0; i--) cout << answer[i] << ' ';

    return 0;
}