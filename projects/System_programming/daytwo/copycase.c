#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int c;
	FILE * in,* out;
	in=fopen("file.in","r");
	out=fopen("file.out","w");
	while((c=fgetc(in))!=EOF)
	{
		if(c!=' ')
		c=c-32;
		fputc(c,out);
	}
	return 0;

}
