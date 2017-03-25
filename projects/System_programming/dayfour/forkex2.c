#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	char * message;
	int n;
	printf("Fork Program Start\n");
	pid=fork();
	switch(pid)
	{
		case -1:
			perror("fork fails Error\n");
			exit(1);
		case 0:
			message="This is the child\n";
			n=5;
			break;
		default:
			message="This is parent\n";
			n=3;
			break;
	}
	for(;n>0;n--)
	{
		puts(message);
		sleep(1);
	}
	exit(0);
}
