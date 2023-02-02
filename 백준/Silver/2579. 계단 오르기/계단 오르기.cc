#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int stair;
    cin >> stair;
    int* memory = new int[stair];
    int* stairs = new int[stair];

    for(int i = 0; i < stair; i++) cin >> stairs[i];

    memory[0] = stairs[0];
    memory[1] = max(stairs[0]+stairs[1], stairs[1]);
    memory[2] = max(stairs[0]+stairs[2], stairs[1]+stairs[2]);
    
    for(int i = 3; i < stair; i++)
    {
        memory[i] = max(memory[i-2] + stairs[i], memory[i-3]+stairs[i-1]+stairs[i]);
    }

    cout << memory[stair-1];
    
    return 0;
}