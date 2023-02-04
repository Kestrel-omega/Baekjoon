#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string emoji;
    int difficulty = 0;

    cin >> emoji;

    for(char c : emoji)
    {
        difficulty++;
        if(c == ':') difficulty++;
        else if(c == '_') difficulty += 5;
    }

    cout << difficulty << endl;
    
    return 0;
}