#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str, '\n'))
	{
		cout << str << endl;
	}

	return 0;
}