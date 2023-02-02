#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num = 0;
	string word = {};
	getline(cin, word);
	for (int i = 0; i < word.length(); i++)
	{
		if (word.at(i) == ' ')
			num++;
	}
	if (word.at(0) == ' ')
		num--;

	if (word.at(word.length() - 1) == ' ')
		num = num - 1;

	cout << num + 1 << endl;
}
