#include <iostream>
#include <tuple>
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
    vector<tuple<int, int, string>> user;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        string name;
        int age;
        cin >> age >> name;
        user.push_back(tuple<int, int, string>(age, i, name));
    }
    sort(user.begin(), user.end());

    for (int i = 0; i < user.size(); i++)
    {
        cout << get<0>(user[i]) << " " << get<2>(user[i]) << "\n";
    }

    return 0;
}
