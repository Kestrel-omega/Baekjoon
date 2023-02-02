#include <iostream>

using namespace std;

bool is_in_circle(int x, int y, int cx, int cy, int r)
{
    int dx = x - cx;
    int dy = y - cy;
    int d = dx * dx + dy * dy;
    return d <= r * r;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, x1, y1, x2, y2, n, cx, cy, r;
    
    cin >> T;

    while(T--)
    {
        int count_inout = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        while(n--)
        {
            cin >> cx >> cy >> r;
            if(is_in_circle(x1, y1, cx, cy, r) ^ is_in_circle(x2, y2, cx, cy, r))
                count_inout++;
        }
        cout << count_inout << "\n";
    }

    return 0;
}