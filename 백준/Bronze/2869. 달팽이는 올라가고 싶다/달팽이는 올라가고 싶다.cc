#include <iostream>
using namespace std;

int main()
{
    int A, B, V, D;
    cin >> A >> B >> V;
    D = (V - B - 1) / (A - B) + 1;
        
    cout << D;
    return 0;
}