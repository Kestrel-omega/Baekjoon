#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N;
    string str;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        cout << str[0] << str[str.size()-1] << endl; 
    }
    
    return 0;
}