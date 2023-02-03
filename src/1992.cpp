#include <iostream>
#include <string>

using namespace std;

string binary[64];
int N;
string result;

void quadTree(int x, int y, int size)
{
    if (size == 1)
    {
        result += binary[x][y];
        return;
    }

    int count = 0;
    
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (binary[i][j] == '1') count++;
        }
    }

    if (count == 0)
    {
        result += '0';
        return;
    }
    else if (count == size * size)
    {
        result += '1';
        return;
    }

    result += '(';
    quadTree(x, y, size / 2);
    quadTree(x, y + size / 2, size / 2);
    quadTree(x + size / 2, y, size / 2);
    quadTree(x + size / 2, y + size / 2, size / 2);
    result += ')';
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> binary[i];

    quadTree(0, 0, N);

    cout << result << "\n";
    
    return 0;
}