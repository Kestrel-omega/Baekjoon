#include <iostream>

using namespace std;

int num = 1000;
bool state[10][10];
bool fixedState[10][10];

void click(int row, int col)
{
    state[row][col] = !state[row][col];
    if (row - 1 >= 0) state[row - 1][col] = !state[row - 1][col];
    if (row + 1 < 10) state[row + 1][col] = !state[row + 1][col];
    if (col - 1 >= 0) state[row][col - 1] = !state[row][col - 1];
    if (col + 1 < 10) state[row][col + 1] = !state[row][col + 1];
}

int check()
{
    int temp = 0;
    for (int row = 1; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (state[row - 1][col])
            {
                click(row, col);
                temp++;
            }
        }
    }

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (state[row][col]) return 1000;
        }
    }
    return temp;
}

int main(void)
{
    char temp;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            cin >> temp;
            if (temp == 'O') fixedState[row][col] = true;
        }
    }
    for (int p = 0; p < 1024; p++)
    {
        for (int row = 0; row < 10; row++)
        {
            for (int col = 0; col < 10; col++)
            {
                state[row][col] = fixedState[row][col];
            }
        }

        int ret = 0;

        for (int i = 0; i < 10; i++)
        {
            if (p & (1 << i))
            {
                ret++;
                click(0, i);
            }
        }

        ret += check();
        if (ret < num) num = ret;
    }

    cout << (num == 1000 ? -1 : num) << '\n';

    return 0;
}