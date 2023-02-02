#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string str;
	cin >> str;
	int num = 0;

	for (int i = 0; i < str.length(); i++) 
    {
		if (str.at(i) >= 'A' && str.at(i) <= 'C')
			num += 3;
		else if (str.at(i) >= 'D' && str.at(i) <= 'F')
			num += 4;
		else if (str.at(i) >= 'G' && str.at(i) <= 'I')
			num += 5;
		else if (str.at(i) >= 'J' && str.at(i) <= 'L')
			num += 6;
		else if (str.at(i) >= 'M' && str.at(i) <= 'O')
			num += 7;
		else if (str.at(i) >= 'P' && str.at(i) <= 'S')
			num += 8;
		else if (str.at(i) >= 'T' && str.at(i) <= 'V')
			num += 9;
		else if (str.at(i) >= 'W' && str.at(i) <= 'Z')
			num += 10;
	}
	printf("%d", num);
    
    return 0;
}