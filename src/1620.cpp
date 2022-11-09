#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    map<string, int> pokemon;
    vector<string> pokemon_name;

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;
        pokemon_name.push_back(name);
        pokemon.insert(pair<string, int>(name, i));
    }
    
    for(int i = 0; i < M; i++)
    {
        string info;
        cin >> info;
        int pokemon_id;
        pokemon_id = atoi(info.c_str());
        if(pokemon_id == 0)
        {
            cout << pokemon[info] << "\n";
        } 
        else
        {
            cout << pokemon_name[pokemon_id-1] << "\n";
        }
    }
    
    return 0;
}
