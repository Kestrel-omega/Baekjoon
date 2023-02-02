#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() 
{
	vector<int> P;
	int N, time_sum = 0;

    cin >> N;
 
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		P.push_back(temp);
	}
 
	sort(P.begin(), P.end());
 
	for(int i = 0; i < N; i++) for(int j = 0; j <= i; j++) time_sum += P[j];
 
	cout << time_sum << endl;
 
	return 0;
}