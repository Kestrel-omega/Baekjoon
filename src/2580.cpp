#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sudoku[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) cin >> sudoku[i][j];
    }

    // i. Check rows

    bool row[9][9] = {false, };

    // ii. Check columns

    bool col[9][9] = {false, };

    // iii. Check 3x3 squares

    bool square[9][9] = {false, };
    
    return 0;
}