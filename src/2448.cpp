#include <iostream>

using namespace std;

char star[3072][6144];

void print_triangle_star(int length, int row, int col)
{
    if(length == 3)
    {
        star[row][col] = '*';
        star[row + 1][col - 1] = '*';
        star[row + 1][col + 1] = '*';
        for(int i = -2; i <= 2; i++) star[row + 2][col + i] = '*';

        return;
    }

    print_triangle_star(length / 2, row, col);
    print_triangle_star(length / 2, row + length / 2, col - length / 2);
    print_triangle_star(length / 2, row + length / 2, col + length / 2);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) for(int j = 0; j < 2*n; j++) star[i][j] = ' ';
    
    print_triangle_star(n, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2 * n - 1; j++) cout << star[i][j];
        cout << "\n";
    }
    
    return 0;
}