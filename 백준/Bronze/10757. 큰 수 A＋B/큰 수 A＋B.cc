#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b, result;
	cin >> a >> b;
	if (a.size() > b.size())
	{
		string c;
		for (int i = 0; i < a.size() - b.size(); i++)
			c += '0';
		b = c + b;
	}
	else
	{
		string c;
		for (int i = 0; i < b.size() - a.size(); i++)
			c += '0';
		a = c + a;
	}
	
	int carry = 0;
	
	while (a.size() != 0 && b.size() != 0)
	{
		int aback = a.back() - '0';
		int bback = b.back() - '0';
		int remain = (carry + aback + bback) % 10;
		carry = (carry + aback + bback) / 10;
		result = (char)(remain + '0') + result;
		a.pop_back();
		b.pop_back();
	}
	if (carry)
		result = (char)(carry + '0') + result;
	cout << result << endl;
	return 0;
}