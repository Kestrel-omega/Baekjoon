#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sudoku[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

bool solve_sudoku(int num)
{
    if(num == 81)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++) cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        return true;
    }

    int x = num / 9;
    int y = num % 9;

    if(sudoku[x][y] != 0) return solve_sudoku(num + 1);
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            if(!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + y / 3][i])
            {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + y / 3][i] = true;
                sudoku[x][y] = i;

                if(solve_sudoku(num + 1)) return true;

                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + y / 3][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if(sudoku[i][j] != 0)
            {
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[(i / 3) * 3 + j / 3][sudoku[i][j]] = true;
            }
        }
    }

    solve_sudoku(0);
    
    return 0;
}