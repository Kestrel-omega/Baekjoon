#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb, check_bomb;

    cin >> str >> bomb;

    for (int i = 0; i < str.length(); i++)
    {
        check_bomb += str[i];

        if (check_bomb.length() >= bomb.length())
        {
            bool is_bomb = true;
            for (int j = 0; j < bomb.length(); j++)
            {
                if (check_bomb[check_bomb.length() - bomb.length() + j] != bomb[j])
                {
                    is_bomb = false;
                    break;
                }
            }

            if (is_bomb) check_bomb.erase(check_bomb.length() - bomb.length(), bomb.length());
        }
    }

    if (check_bomb.length() == 0) cout << "FRULA";
    else cout << check_bomb;
    
    return 0;
}