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
    vector<string> words;

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        string word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < M; i++)
    {
        string check_word;
        cin >> check_word;
        if(binary_search(words.begin(), words.end(), check_word)) count++;
    }

    cout << count;

    return 0;
}