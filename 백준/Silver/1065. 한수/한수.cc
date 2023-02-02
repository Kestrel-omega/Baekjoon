#include<iostream>  
using namespace std;

int cal(int in)
{
	int ans, in1, in2, in3;
	if (in < 100)
		return in;

	ans = 99;

	for (int i = 100;i <= in;++i)
	{
		in1 = i / 100;
		in2 = (i - in1 * 100) / 10;
		in3 = i % 10;


		if ((in1 - in2) == (in2 - in3))
			ans++;
	}

	return ans;
}
int main(void) 
{
	int in;

	cin >> in;

	int a = cal(in);

	cout << a << endl;

}
