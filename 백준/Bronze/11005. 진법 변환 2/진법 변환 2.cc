#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, notation, temp = 0;
    vector<char> result;

    cin >> num >> notation;

    while(num != 0)
    {
        temp = num % notation;
        num /= notation;

        if(temp >= 10)
        {
            result.push_back(temp - 10 + 'A');
        }
        else
        {
            result.push_back(temp + '0');
        }
    }

    for(int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    return 0;
}
