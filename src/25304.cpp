#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, N, a, b;

    cin >> X >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        X -= a*b;
    }

    if(X == 0) cout << "Yes";
    else cout << "No";

    return 0;
}