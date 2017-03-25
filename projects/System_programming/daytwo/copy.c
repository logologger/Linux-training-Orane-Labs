//This sample program is for performing copy operation from one file to another file with the help of system calls read ,write and open
//this program is a property of Mr. Rajat Singh Bhadauria
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	char buffer[1024];
	int out1,out2;
	char c;
	out1=open("file1.txt",O_WRONLY);
	out2=open("file2.txt",O_RDONLY);
	while(read(out2,&c,1)==1)
	{
		write(out1,&c,1);
		
	}


	return 0;
}
