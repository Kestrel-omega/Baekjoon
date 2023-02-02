#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<pair<int, string>> words;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        words.push_back(pair<int, string>(word.size(), word));
    }
    sort(words.begin(), words.end());

    vector<pair<int, string>>::iterator i;
    for (i = words.begin(); i != words.end(); i++)
    {
        if(i->second != (i+1)->second) cout << i->second << "\n";
    }

    return 0;
}
