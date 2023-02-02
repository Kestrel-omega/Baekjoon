#include <iostream>
using namespace std;

int main()
{
    int hour, min;
    cin >> hour >> min;
    
    if(min<45)
    {
        hour -= 1;
        min += 60;
    }
    if(hour == -1) hour = 23;
    
    min -= 45;
    
    cout << hour << " " << min << endl;
}