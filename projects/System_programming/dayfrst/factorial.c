#include<stdio.h>
int fact(int n)
{
	int f=1,i;
	
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	printf("the factorial of the number is %d",f);
	return 0;
}
