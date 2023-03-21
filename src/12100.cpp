#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 12100 2048 (Easy)

int N;
int board[20][20];
int max_block = 0;

void move(int dir)
{
    if (dir == 0)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> temp;
            int idx = 0;

            for (int j = 0; j < N; j++)
            {
                if (board[i][j] != 0) temp.push_back(board[i][j]);
            }
            for (int j = 0; j < N; j++) board[i][j] = 0;
            
            for (int j = 0; j < temp.size(); j++)
            {
                if (j + 1 < temp.size() && temp[j] == temp[j + 1])
                {
                    board[i][idx++] = temp[j] * 2;
                    max_block = max(max_block, board[i][idx - 1]);
                    j++;
                }
                else board[i][idx++] = temp[j];
            }
        }
    }
    else if (dir == 1)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> temp;
            int idx = 0;

            for (int j = 0; j < N; j++)
            {
                if (board[j][i] != 0) temp.push_back(board[j][i]);
            }
            for (int j = 0; j < N; j++) board[j][i] = 0;
            
            for (int j = 0; j < temp.size(); j++)
            {
                if (j + 1 < temp.size() && temp[j] == temp[j + 1])
                {
                    board[idx++][i] = temp[j] * 2;
                    max_block = max(max_block, board[idx - 1][i]);
                    j++;
                }
                else board[idx++][i] = temp[j];
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> temp;
            int idx = N - 1;

            for (int j = N - 1; j >= 0; j--)
            {
                if (board[i][j] != 0) temp.push_back(board[i][j]);
            }
            for (int j = 0; j < N; j++) board[i][j] = 0;
            
            for (int j = 0; j < temp.size(); j++)
            {
                if (j + 1 < temp.size() && temp[j] == temp[j + 1])
                {
                    board[i][idx--] = temp[j] * 2;
                    max_block = max(max_block, board[i][idx + 1]);
                    j++;
                }
                else board[i][idx--] = temp[j];
            }
        }
    }
    else if (dir == 3)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> temp;
            int idx = N - 1;

            for (int j = N - 1; j >= 0; j--)
            {
                if (board[j][i] != 0) temp.push_back(board[j][i]);
            }
            for (int j = 0; j < N; j++) board[j][i] = 0;
            
            for (int j = 0; j < temp.size(); j++)
            {
                if (j + 1 < temp.size() && temp[j] == temp[j + 1])
                {
                    board[idx--][i] = temp[j] * 2;
                    max_block = max(max_block, board[idx + 1][i]);
                    j++;
                }
                else board[idx--][i] = temp[j];
            }
        }
    }
}

void dfs(int count)
{
    if (count == 5) return;

    int temp[20][20];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) temp[i][j] = board[i][j];
    }
    for (int i = 0; i < 4; i++)
    {
        move(i);
        dfs(count + 1);

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++) board[j][k] = temp[j][k];
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            max_block = max(max_block, board[i][j]);
        }
    }

    dfs(0);

    cout << max_block << endl;

    return 0;
}