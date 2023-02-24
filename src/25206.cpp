#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int idx = 0;
    float cnt = 0;
    float sum = 0;
    float temp = 0;
    cin >> str;

    for(int i = 0; i < 20; i++)
    {
        if(idx%3 == 1)
        {
            cnt++;
            sum += stof(str);
            temp = stof(str);
        }
        else if(idx%3 == 2 && str == "P")
        {
            cnt--;
            sum -= temp;
        }
        cin >> str;
        idx++;
    }

    cout << sum / cnt;
    
    return 0;
}