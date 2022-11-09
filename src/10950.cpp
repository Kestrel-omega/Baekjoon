#include <iostream>
#define ADD(a, b) a + b
int main()
{
    int a, b, T;
    std::cin >> T;
    for(int i=0;i<T;i++){std::cin >> a >> b; std::cout << ADD(a, b) << std::endl;}
    return 0;
}