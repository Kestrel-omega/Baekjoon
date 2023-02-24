#include <iostream>
#include <queue>

using namespace std;

int basket[101] = {0,};

void rotate(int begin, int end, int mid)
{
    queue<int> temp;
    for(int i = mid; i <= end; i++) temp.push(basket[i]);
    for(int i = begin; i < mid; i++) temp.push(basket[i]);
    for(int i = begin; i <= end; i++)
    {
        basket[i] = temp.front();
        temp.pop();
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) basket[i] = i;

    while(M--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        rotate(i, j, k);
    }

    for (int i = 1; i <= N; i++) cout << basket[i] << " ";
    
    return 0;
}