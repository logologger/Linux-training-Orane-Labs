#include<stdio.h>
int main()
{
	int c[]={1,2,3};
	int *choice=c;
	c[0]=2;
	c[1]=c[2];
	c[2]=*choice;
	printf("%i",c[2]);
	return 0;
}
