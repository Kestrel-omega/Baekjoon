// 금요일이 없는 시간표

#include <iostream>
#include <vector>

using namespace std;

typedef struct _classTime
{
    int weekday;
    int start;
    int end;
} classTime;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, want, count = 0;
    vector<classTime> classTimeList;
    bool is_possible[4][10] = {true, };

    cin >> n >> want;

    for (int i = 0; i < n; i++)
    {
        classTime temp;
        cin >> temp.weekday >> temp.start >> temp.end;
        if(temp.weekday != 5) classTimeList.push_back(temp);
    }

    for(classTime temp : classTimeList)
    {
        for(int i = temp.start; i <= temp.end; i++)
        {
            is_possible[temp.weekday][i] = false;
        }
    }







    
    return 0;
}