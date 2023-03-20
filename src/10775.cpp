#include <iostream>
#include <algorithm>

using namespace std;

// 10775 공항

int G, P;
int parent[100001];
int answer = 0;

int find(int x) 
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> G >> P;

    for (int i = 1; i <= G; i++) parent[i] = i;
    for (int i = 0; i < P; i++) 
    {
        int g;
        cin >> g;
        int p = find(g);
        if (p == 0) break;
        else
        {
            answer++;
            parent[p] = p - 1;
        }
    }

    cout << answer;

    return 0;
}