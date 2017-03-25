#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	pid_t new_pid;
	new_pid=fork();
	printf("return value of fork is %d",new_pid);
	switch(new_pid)
	{
		case -1:
			printf("Error\n");
			break;
		case 0:
			printf("Child Creation Success\n");
			break;
		default:
			printf("you are in parent\n");
			break;
	}

}
