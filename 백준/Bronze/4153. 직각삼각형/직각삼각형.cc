#include <iostream>

using namespace std;


int main()
{
	int left, max, tri[3];
	while (1)
	{
		cin >> tri[0] >> tri[1] >> tri[2];
		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
			break;

		left = 0;
		max = 0;

		for (int i = 0; i < 3; i++)
		{
			if (tri[i] > max)
				max = tri[i];
		}
		for (int j = 0; j < 3; j++)
		{
			if (tri[j] != max)
				left += tri[j] * tri[j];
		}
		if (max * max == left)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}
