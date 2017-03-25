#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void ouch(int sig)
{
	printf("Ouch ----I got a Signal %d\n",sig);
	(void)signal(SIGINT,SIG_DFL);
}
int main()
{
	(void)signal(SIGINT,ouch);
	while(1)
	{
		printf("Hello World\n");
		sleep(1);
	}
}
