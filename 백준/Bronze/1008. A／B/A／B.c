#include <stdio.h>

int main()
{
	double x,y,result;
    scanf("%lf %lf",&x,&y);
    result = x / y;
    printf("%0.9lf",result);	
	return 0;
}