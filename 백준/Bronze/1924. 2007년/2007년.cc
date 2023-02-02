#include <iostream>
using namespace std;

int main()
{
	int monthDays[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	int months = 0, days = 0, totalDays = 0, weekDays = 0;


	cin >> months >> days;

	for (int a = 1;a <= months;a++)
	{
		totalDays = totalDays + monthDays[a-1];
	}
	totalDays = totalDays + days;

	weekDays = totalDays % 7;

	switch(weekDays)
	{
	case 1:
		cout << "MON" << endl;
		break;
	case 2:
		cout << "TUE" << endl;
		break;
	case 3:
		cout << "WED" << endl;
		break;
	case 4:
		cout << "THU" << endl;
		break;
	case 5:
		cout << "FRI" << endl;
		break;
	case 6:
		cout << "SAT" << endl;
		break;
	case 0:
		cout << "SUN" << endl;
		break;
	}

	return 0;
}