#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;

    for(int i = 0; i < word.size(); i++)
    {
        if(word[i] < 'a') word[i] += ('a'-'A');
        else word[i] -= ('a'-'A');
    }

    cout << word;

    return 0;
}