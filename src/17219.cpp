#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string site;
    string password;
    map<string, string> inform;

    cin >> N >> M;

    while(N--)
    {
        cin >> site >> password;
        inform.insert(make_pair(site, password));
    }

    while(M--)
    {
        cin >> site;
        cout << inform[site] << endl;
    }

    
    return 0;
}