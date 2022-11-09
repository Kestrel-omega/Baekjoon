#include <iostream>
#include <string>

using namespace std;

string WB = "WBWBWBWB";
string BW = "BWBWBWBW";

string board[50];

int main()
{
    int N, M;
    cin >> N >> M;
    int count = 64;
    for(int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    // WB start
    for(int i = 0; i < N-7; i++)
    {
        for(int j = 0; j < M-7; j++)
        {
            int check = 0;
            for(int k = 0; k < 8; k++)
            {
                if(k%2 == 0)
                {
                    for(int l = 0; l < 8; l++)
                    {
                        if(WB[l]!=board[i+k][j+l]) check++;
                    }
                }
                else
                {
                    for(int l = 0; l < 8; l++)
                    {
                        if(BW[l]!=board[i+k][j+l]) check++;
                    }
                }
            }
            if(check < count) count = check;
        }
    }

    // BW start
    for(int i = 0; i < N-7; i++)
    {
        for(int j = 0; j < M-7; j++)
        {
            int check = 0;
            for(int k = 0; k < 8; k++)
            {
                if(k%2 == 0)
                {
                    for(int l = 0; l < 8; l++)
                    {
                        if(BW[l]!=board[i+k][j+l]) check++;
                    }
                }
                else
                {
                    for(int l = 0; l < 8; l++)
                    {
                        if(WB[l]!=board[i+k][j+l]) check++;
                    }
                }
            }
            if(check < count) count = check;
        }
    }

    cout << count;

    return 0;
}