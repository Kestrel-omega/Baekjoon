#include <iostream>

using namespace std;

int N, paper[2187][2187], result[3] = {0, 0, 0}; // -1, 0, 1

void divide(int x, int y, int size)
{
    // cout << "-1 : " << result[0] << " / 0 : " << result[1] << " / 1 : " << result[2] << "\n";
    bool is_all_0 = true;
    int count = 0;
    int size_square = size * size;
    int minus_size_square = (-size) * size;
    
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            count += paper[i][j];
            if (paper[i][j] != 0) is_all_0 = false;
        }
    }


    if (size == 1)
    {
        result[paper[x][y] + 1]++;
        return;
    }

    if (is_all_0 && count == 0)
    {
        result[1]++;
        return;
    }
    else if (count == size_square)
    {
        result[2]++;
        return;
    }
    else if (count == minus_size_square)
    {
        result[0]++;
        return;
    }

    divide(x, y, size / 3);
    divide(x, y + size / 3, size / 3);
    divide(x, y + 2 * size / 3, size / 3);
    divide(x + size / 3, y, size / 3);
    divide(x + size / 3, y + size / 3, size / 3);
    divide(x + size / 3, y + 2 * size / 3, size / 3);
    divide(x + 2 * size / 3, y, size / 3);
    divide(x + 2 * size / 3, y + size / 3, size / 3);
    divide(x + 2 * size / 3, y + 2 * size / 3, size / 3);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) cin >> paper[i][j];
    }

    divide(0, 0, N);

    for(int i = 0; i < 3; i++) cout << result[i] << "\n";
    
    return 0;
}