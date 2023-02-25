#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string board[5];
    for(int i = 0; i < 5; i++) cin >> board[i];

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 5; j++) if(board[j].length() > i) cout << board[j][i];
    }
    
    return 0;
}