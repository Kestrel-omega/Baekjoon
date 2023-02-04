#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, idx, count;
    cin >> T;

    while(T--)
    {
        idx = 0;
        count = 1;

        cin >> N;

        vector<pair<int, int>> document_interview;

        for (int i = 0; i < N; i++)
        {
            int document, interview;
            cin >> document >> interview;
            document_interview.push_back(make_pair(document, interview));
        }

        sort(document_interview.begin(), document_interview.end());

        for (int i = 1; i < N; i++)
        {
            if (document_interview[idx].second > document_interview[i].second)
            {
                idx = i;
                count++;
            }
        }

        cout << count << '\n';
    }
    
    return 0;
}