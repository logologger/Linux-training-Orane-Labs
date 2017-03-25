#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	time_t timeval;
	(void)time(&timeval);
	//printf("The time is %s",time(&timeval));
	printf("The date is %s",ctime(&timeval));
	return 0;
}
