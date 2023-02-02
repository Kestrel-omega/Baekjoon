#include <iostream>
using namespace std;

int main() 
{
	int inTrain = 0, in = 0, out = 0, maxInTrain = 0;

	for (int a = 0;a < 4;a++)
	{
		cin >> out >> in;
		inTrain = inTrain + in - out;
		if (maxInTrain < inTrain)
			maxInTrain = inTrain;
	}

	cout << maxInTrain << endl;

	return 0;
}