#include <iostream>

int main()
{
    int hour = 0;
    int min = 0;
    int dhour, dmin, tmin;

    std::cin >> hour >> min >> tmin;
    dhour = tmin / 60;
    dmin = tmin % 60;
    hour += dhour;
    min += dmin;

    if(min > 59)
    {
        hour++;
        min -= 60;
    }
    if(hour > 23)
    {
        hour -= 24;
    }

    std::cout << hour << " " << min;

    return 0;
}