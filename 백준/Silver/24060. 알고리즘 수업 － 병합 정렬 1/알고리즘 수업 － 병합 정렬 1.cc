#include <iostream>

using namespace std;

int input_count = 0;

void merge(int A[], int p, int q, int r, int K)
{
    int temp[r + 2];
    int i = p, j = q + 1, t = 1;

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j]) temp[t++] = A[i++];
        else temp[t++] = A[j++];
    }
    while (i <= q) temp[t++] = A[i++];
    while (j <= r) temp[t++] = A[j++];

    i = p;
    t = 1;

    while (i <= r)
    {
        A[i++] = temp[t++];
        input_count++;
        if (input_count == K) cout << temp[t - 1];
    }
}

void merge_sort(int A[], int start, int end, int K)
{
    int p = start, r = end, q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(A, p, q, K);
        merge_sort(A, q + 1, r, K);
        merge(A, p, q, r, K);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int A[500001];

    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> A[i];
    merge_sort(A, 0, N-1, K);
    if(input_count < K) cout << -1;

    return 0;
}