#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 1;
    int max_pos = 1;
    int max = 0;
    int num = 0;

    while(count < 82)
    {
        cin >> num;
        if(num > max)
        {
            max = num;
            max_pos = count;
        }
        count++;
    }

    if(max_pos % 9 == 0) cout << max << endl << (max_pos)/9 << " " << 9;
    else cout << max << endl << max_pos/9+1 << " " << max_pos%9;

    return 0;
}