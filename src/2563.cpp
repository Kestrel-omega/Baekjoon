#include <iostream>

using namespace std;

bool plot[100][100] = {false,};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x, y;
    int area = 0;
    cin >> N;
    while(N--)
    {
        cin >> x >> y;
        for(int i = x; i < x+10; i++)
        {
            for(int j = y; j < y+10; j++)
            {
                if(plot[i][j] == false) 
                {
                    area++;
                    plot[i][j] = true;
                }
            }
        }

    }

    cout << area;
    
    return 0;
}