#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int ans[100];
int gcd(int a, int b) 
{
	return a % b ? gcd(b, a%b) : b;
}
int main() 
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
        cin >> arr[i];
	sort(arr, arr + n);
	int sub = arr[1] - arr[0];
	for (int i = 2; i < n; i++) 
        sub = gcd(sub, arr[i] - arr[i - 1]);
	int count = 0;
	for (int i = 1; i*i <= sub; i++) 
    {
		if (sub%i == 0) 
        {
			ans[count++] = i;
			if (i != sub / i) 
                ans[count++] = sub / i;
		}
	}
	sort(ans, ans + count); 
    
	for (int i = 0; i < count; i++) 
    {
		if (ans[i] != 1) 
            cout << ans[i] << " ";
	}
}