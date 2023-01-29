#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<int> sequence;
    map<string, string> map_sequence;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        sequence.push_back(num);
    }

    sort(sequence.begin(), sequence.end());

    do
    {
        string temp = "";
        for (int i = 0; i < M; i++) temp += to_string(sequence[i]) + " ";
        map_sequence.insert(make_pair(temp, temp));
        
    } while (next_permutation(sequence.begin(), sequence.end()));

    for(auto it = map_sequence.begin(); it != map_sequence.end(); it++)
    {
        cout << it->second << "\n";
    }
    
    return 0;
}