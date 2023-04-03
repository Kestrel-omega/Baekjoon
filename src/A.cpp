#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string fortune;
    queue<char> YONSEI;
    queue<char> KOREA;

    cin >> fortune;

    for(char c : fortune)
    {
        if(c == 'Y' && YONSEI.size() == 0) YONSEI.push(c);
        if(c == 'O' && YONSEI.size() == 1) YONSEI.push(c);
        if(c == 'N' && YONSEI.size() == 2) YONSEI.push(c);
        if(c == 'S' && YONSEI.size() == 3) YONSEI.push(c);
        if(c == 'E' && YONSEI.size() == 4) YONSEI.push(c);
        if(c == 'I' && YONSEI.size() == 5) YONSEI.push(c);

        if(c == 'K' && KOREA.size() == 0) KOREA.push(c);
        if(c == 'O' && KOREA.size() == 1) KOREA.push(c);
        if(c == 'R' && KOREA.size() == 2) KOREA.push(c);
        if(c == 'E' && KOREA.size() == 3) KOREA.push(c);
        if(c == 'A' && KOREA.size() == 4) KOREA.push(c);

        if(YONSEI.size() == 6) 
        {
            cout << "YONSEI";
            break;
        }
        if(KOREA.size() == 5) 
        {
            cout << "KOREA";
            break;
        }
    }
    
    return 0;
}