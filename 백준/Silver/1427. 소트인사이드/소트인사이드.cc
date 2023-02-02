#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int i, int j)
{
    return j < i;
}

int main()
{
    string N;
    cin >> N;

    sort(N.begin(), N.end(), compare);

    cout << N;

    return 0;
}