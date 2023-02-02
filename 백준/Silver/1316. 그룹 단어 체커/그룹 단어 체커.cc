#include <iostream>

using namespace std;

int main()
{
    int N;
    int count = 0;

    cin >> N;
        
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        bool check_alphabet[26] = {false, };
        count++;

        for(int j = 0; j < word.size(); j++)
        {
            
            if(word[j] == word[j+1]) 
            {
                continue;
            }
            else if(check_alphabet[(int)word[j]-'a'] == true)
            {
                count--;
                break;
            }
            else check_alphabet[(int)word[j]-'a'] = true;
        }
    }
    cout << count;

    return 0;
}