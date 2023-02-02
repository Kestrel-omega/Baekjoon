#include<stdio.h>

int d[10001];
int dn(int i) 
{
	int res = i;
	if (i >= 10000) 
    {
        res += i / 10000; 
        i %= 10000;
    }
	if (i >= 1000) 
    {
        res += i / 1000; 
        i %= 1000;
    }
	if (i >= 100) 
    {
        res += i / 100; 
        i %= 100;
    }
	if (i >= 10) 
    {
        res += i / 10; 
        i %= 10;
    }
	return res += i;
}
int main() 
{
	for (int i = 1; i <= 10000; i++) 
    {
		d[dn(i)] = 1;
		if (!d[i])
        {
            printf("%d\n", i);
        }
	}
    
    return 0;
}