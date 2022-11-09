#include <iostream>

using namespace std;

int main()
{
    int student[30] = {0,};

    for(int i = 0; i < 28; i++)
    {
        int apply;
        cin >> apply;
        student[apply-1] = 1;
    }

    for(int i = 0; i < 30; i++)
    {
        if(student[i] == 0) cout << i+1 << "\n";
    }
}