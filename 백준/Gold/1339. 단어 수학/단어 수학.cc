#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum = 0;
    vector<pair<int, char>> alphabet;
    for(int i = 0; i < 26; i++) alphabet.push_back(make_pair(0, i + 'A'));

    cin >> N;

    while(N--)
    {
        string str;
        cin >> str;

        for(int i = 0; i < str.length(); i++) alphabet[str[i] - 'A'].first += pow(10, str.length() - i - 1);
    }

    sort(alphabet.begin(), alphabet.end(), greater<pair<int, char>>());
    for(int i = 9; i > 0; i--) sum += alphabet[9-i].first * i;

    cout << sum << endl;
    
    return 0;
}