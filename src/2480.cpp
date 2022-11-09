#include <iostream>

int main()
{
    int a, b, c;
    int price;
    std::cin >> a >> b >> c;

    if(a == b && b == c) price = 10000 + a * 1000;
    else if(a == b || a == c) price = 1000 + a * 100;
    else if(b == c) price = 1000 + b * 100;
    else
    {
        if(a > b && a > c) price = a * 100;
        else if(b > a && b > c) price = b * 100;
        else price = c * 100;
    }

    std::cout << price;

    return 0;
}