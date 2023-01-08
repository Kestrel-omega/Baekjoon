#include <iostream>

using namespace std;

int euclidean(int a, int b)
{
	return a % b ? euclidean(b, a%b) : b;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;

    cin >> T;

    while(T--)
    {
        cin >> A >> B;
        cout << A*B/euclidean(A, B) << endl;
    }

    return 0;
}